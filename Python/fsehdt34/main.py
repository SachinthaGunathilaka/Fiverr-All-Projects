class File:
    def __init__(self, filename):
        self.owner = "default"
        self.filename = filename
        self.parent = ""

    def chown(self, new_owner):
        self.owner = new_owner

    def __str__(self):
        return self.filename

    def getDetails(self):
        return self.filename + " (" + self.owner + ")"


class PlainFile(File):
    def __init__(self, filename):
        File.__init__(self, filename)


class Directory(File):
    def __init__(self, filename, children):
        File.__init__(self, filename)
        self.children = children
        for child in self.children:
            child.parent = self

    def ls(self, tab_spaces=0):

        print('\t' * tab_spaces, end="")
        print(self)
        tab_spaces += 1

        for child in self.children:
            if child.__class__.__name__ == "PlainFile":
                print('\t' * tab_spaces, end="")
                print(child)
            else:
                child.ls(tab_spaces)

    def ls(self, arg, tab_spaces=0):

        print('\t' * tab_spaces, end="")
        if arg == 'l':
            print(self.getDetails())

        else:
            print(self)
        tab_spaces += 1

        for child in self.children:
            if child.__class__.__name__ == "PlainFile":
                print('\t' * tab_spaces, end="")
                if arg == 'l':
                    print(child.getDetails())

                else:
                    print(child)
            else:
                child.ls(arg, tab_spaces)


class FileSystem:
    def __init__(self, root):
        self.root = root
        self.current = root
        # self.parents = []

    def pwd(self):
        print("\'", end="")
        print(self.current.filename, end="")
        print("\'")

    def ls(self, arg):
        self.current.ls(arg)

    def cd(self, directory_name):
        if directory_name != "..":
            is_exist = False
            for child in self.current.children:
                if (child.filename == directory_name) and (child.__class__.__name__ == "Directory"):
                    self.current = child

                    is_exist = True
                    break

            if not is_exist:
                print("The directory does not exist!")

        else:
            if self.current.parent == "":
                return

            self.current = self.current.parent

    def chown(self, owner):
        self.current.chown(owner)

    def chown_r(self, owner, directory=None):
        if not directory:
            directory = self.root

        directory.chown(owner)
        for child in directory.children:
            child.chown(owner)

            if child.__class__.__name__ == "Directory":
                self.chown_r(owner, child)

    def create_file(self, name):
        file = PlainFile(name)
        owner = input("Who owns the file : ")
        file.chown(owner)

        is_exist = False
        for child in self.current.children:
            if (child.filename == name) and (child.__class__.__name__ == "PlainFile"):
                is_exist = True
                print("File already exists!")
                break

        if not is_exist:
            self.current.children.append(file)

    def mkdir(self, name):
        directory = Directory(name, [])
        owner = input("Who owns the directory : ")
        directory.chown(owner)

        is_exist = False
        for child in self.current.children:
            if (child.filename == name) and (child.__class__.__name__ == "Directory"):
                is_exist = True
                print("Directory already exists!")
                break

        if not is_exist:
            self.current.children.append(directory)

    def rm(self, name):
        delete_index = -1
        for index in range(len(self.current.children)):
            if self.current.children[index].filename == name:
                if self.current.children[index].__class__.__name__ == "PlainFile":
                    delete_index = index
                    break
                else:
                    if len(self.current.children[index].children) != 0:
                        print("The directory isn’t empty")
                        delete_index = -2
                        break

                    else:
                        delete_index = index
                        break

        if delete_index >= 0:
            del self.current.children[delete_index]

        elif delete_index == -1:
            print("Not found")

    def find(self, name):
        directories = [self.current]
        file = None

        while (len(directories) != 0) and (not file):
            temp = directories[0]

            for child in temp.children:
                if child.filename == name:
                    file = child
                    break

                if child.__class__.__name__ == "Directory":
                    directories.append(child)
            del directories[0]

        if file:
            path = file.filename

            while file.parent != "":
                path = file.parent.filename + "/" + path
                file = file.parent

            print("\'" + path + "\'")

        else:
            print("False")

    def mv(self, current_path, destination_path):
        path_dirs = current_path.split("/")
        dest_dirs = destination_path.split("/")

        current_dir = self.root

        index = -1
        for i in range(len(path_dirs)):
            for j in range(len(current_dir.children)):
                if current_dir.children[j].filename == path_dirs[i]:

                    if i == len(path_dirs) - 1:
                        index = j

                    current_dir = current_dir.children[j]
                    break

        dest_dir = self.root
        for i in range(len(dest_dirs)):
            for child in dest_dir.children:
                if child.filename == dest_dirs[i]:
                    dest_dir = child
                    break

        dest_dir.children.append(current_dir)
        del current_dir.parent.children[index]


root = Directory("root",
                 [PlainFile("boot.exe"),
                  Directory("home", [
                      Directory("james",
                                [PlainFile("example_image.jpg"),
                                 PlainFile("example_text.txt")]),
                      Directory("thomas", [PlainFile("example_image1.jpg")])])])

fs = FileSystem(root)


def printUsage():
    print("Usage : ")
    print("\tls - show contents of a directory and all the content of all subdirectories\n"
          "\tls -l - show contents of a directory with owner\n"
          "\tpwd - show the current working directory\n"
          "\tcd <directory_name> - change directory\n"
          "\tchown -r <owner> - change owner\n"
          "\ttouch <filename> - create file\n"
          "\tmkdir <directory_name> - create directory\n"
          "\trm <name> - remove directory or plain file\n"
          "\tfind <name> - find file and show the path\n"
          "\tmv <current_path> <destination_path> move a file")


printUsage()
while True:
    data = input(">>").lower()
    command = data.split()
    if (len(command) == 1) and (command[0] == "ls"):
        fs.ls('')

    elif (len(command) == 2) and (command[0] == "ls") and (command[1] == "-l"):
        fs.ls('l')

    elif command[0] == "pwd":
        fs.pwd()

    elif command[0] == "cd":
        fs.cd(command[1])

    elif command[0] == "chown" and command[1] == "-r":
        option = input(
            "Should these permissions be applied to all files in the system or just one?\n"
            "Enter ‘all’ or ‘one’? ").lower()

        while option not in ["all", "one"]:
            print("Invalid Input")
            option = input(
                "Should these permissions be applied to all files in the system or just one?\n"
                "Enter ‘all’ or ‘one’? ").lower()

        if option == "all":
            fs.chown_r(command[2])

        else:
            fs.chown(command[2])



    elif command[0] == "touch":
        fs.create_file(command[1])

    elif command[0] == "mkdir":
        fs.mkdir(command[1])

    elif command[0] == "rm":
        fs.rm(command[1])

    elif command[0] == "find":
        fs.find(command[1])

    elif command[0] == "mv":
        fs.mv(command[1], command[2])

    else:
        printUsage()

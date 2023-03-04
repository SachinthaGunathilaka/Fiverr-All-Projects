#include "Entry.h"
#include "Directory.h"
#include "File.h"

#include <sstream>
#include <string>


//This function finds directory with the given name(2nd argument) from the given path(1st argument)
//For example below finds "world" directory from the root directory
//find_directory(&root, "world");
Entry *find_directory(Directory *root, const std::string &path) {
    //Implement your code here.
    //Leverage find member function.
    //...
    Entry *entry = root;
    Directory *dir = root;
    std::string token;
    std::istringstream iss(path);

    std::getline(iss, token, '/');
    if (token != "root") {
        std::cout << "null" << std::endl;
        return nullptr;
    }
    bool isEnd = false;
    while (std::getline(iss, token, '/')) {
        if (isEnd) {
            std::cout << "end" << std::endl;
            return nullptr;
        }
        entry = dir->find(token);
        if ((entry != nullptr) && (typeid(*entry).name() == typeid(Directory).name())) {
            dir = dynamic_cast<Directory *>(entry);
        } else {
            isEnd = true;
        }
    }
    return entry;


}

void exec_cmd(Directory *root, std::string cmd) {
    //*****Do NOT MODIFY START*****
    std::istringstream iss1(cmd), iss2(cmd);
    std::string token;
    std::getline(iss2, token, ' ');
    std::getline(iss1, token, ' ');
    //*****DO NOT MODIFY END*****

    //Implement your code here
    //...

    if (token == "mkdir") {
        std::string path, dir_name;
        std::getline(iss2, path);
        int last_index = path.find_last_of('/');
        dir_name = path.substr(last_index + 1);

        auto *dir = dynamic_cast<Directory *> (find_directory(root, path.substr(0, last_index)));
        if (dir != nullptr) {
            if (dir->find(dir_name) == nullptr) {
                dir->add(new Directory(dir_name));
            } else {
                std::cout << "directory already exists" << std::endl;
            }

        } else {
            std::cout << "invalid path" << std::endl;
        }
    } else if (token == "touch") {

        std::string path, file_name;
        std::getline(iss2, path);
        int last_index = path.find_last_of('/');
        file_name = path.substr(last_index + 1);

        auto *dir = dynamic_cast<Directory *> (find_directory(root, path.substr(0, last_index)));
        if (dir != nullptr) {
            if (dir->find(file_name) == nullptr) {
                dir->add(new File(file_name));
            } else {
                std::cout << "file already exists" << std::endl;
            }

        } else {
            std::cout << "invalid path" << std::endl;
        }

    } else if (token == "echo") {

        std::string path, file_name, content;
        std::getline(iss2, path, ' ');
        std::getline(iss2, content);
        int last_index = path.find_last_of('/');
        file_name = path.substr(last_index + 1);

        auto *dir = dynamic_cast<Directory *> (find_directory(root, path.substr(0, last_index)));
        if (dir != nullptr) {
            File *new_file;
            Entry *entry = dir->find(file_name);
            if (entry == nullptr) {
                new_file = new File(file_name);
            } else {
                std::cout << "file updated" << std::endl;
                new_file = dynamic_cast<File *>(entry);
            }
            new_file->content(content);
            dir->add(new_file);

        } else {
            std::cout << "invalid path" << std::endl;
        }


    } else if (token == "cat") {
        std::string path, file_name;
        std::getline(iss2, path);
        int last_index = path.find_last_of('/');
        file_name = path.substr(last_index + 1);

        auto *dir = dynamic_cast<Directory *> (find_directory(root, path.substr(0, last_index)));
        if (dir != nullptr) {
            Entry *entry = dir->find(file_name);
            if ((entry != nullptr) && (typeid(*entry).name() == typeid(File).name())) {
                std::cout << entry->content() << std::endl;
            } else {
                std::cout << "no such file" << std::endl;
            }

        } else {
            std::cout << "no such file" << std::endl;
        }


    } else if (token == "ls") {
        std::string path, dir_name;
        std::getline(iss2, path);

        auto *dir = dynamic_cast<Directory *> (find_directory(root, path));
        if (dir != nullptr) {
            std::cout << dir->content() << std::endl;
        } else {
            std::cout << "no such directory" << std::endl;
        }

    } else if (token == "tree") {

        std::string path, dir_name;
        std::getline(iss2, path);

        auto *dir = dynamic_cast<Directory *> (find_directory(root, path));
        if (dir != nullptr) {
            std::cout << *dir << std::endl;
        } else {
            std::cout << "no such directory" << std::endl;
        }


    } else if (token == "mv") {
        std::string s_path, d_path, file_name;
        std::getline(iss2, s_path, ' ');
        std::getline(iss2, d_path);
        int last_index = s_path.find_last_of('/');
        file_name = s_path.substr(last_index + 1);

        auto *s_dir = dynamic_cast<Directory *> (find_directory(root, s_path.substr(0, last_index)));
        auto *d_dir = dynamic_cast<Directory *> (find_directory(root, d_path));
        if ((s_dir == nullptr) || (d_dir == nullptr)) {
            std::cout << "no such file or directory" << std::endl;
        } else {
            Entry *entry = s_dir->find(file_name);
            if (entry != nullptr) {
                d_dir->add(entry);
                s_dir->remove(file_name);
            } else {
                std::cout << "no such file or directory" << std::endl;
            }
        }
    } else if (token == "cp") {
        std::string s_path, d_path, file_name;
        std::getline(iss2, s_path, ' ');
        std::getline(iss2, d_path);
        int last_index = s_path.find_last_of('/');
        file_name = s_path.substr(last_index + 1);

        auto *s_dir = dynamic_cast<Directory *> (find_directory(root, s_path.substr(0, last_index)));
        auto *d_dir = dynamic_cast<Directory *> (find_directory(root, d_path));
        if ((s_dir == nullptr) || (d_dir == nullptr)) {
            std::cout << "no such file or directory" << std::endl;
        } else {
            Entry *entry = s_dir->find(file_name);
            if (entry != nullptr) {
                d_dir->add(entry);
            } else {
                std::cout << "no such file or directory" << std::endl;
            }
        }
    } else if (token == "rmdir") {
        std::string path, dir_name;
        std::getline(iss2, path);
        int last_index = path.find_last_of('/');
        dir_name = path.substr(last_index + 1);

        auto *dir = dynamic_cast<Directory *> (find_directory(root, path.substr(0, last_index)));
        if (dir != nullptr) {
            Entry *entry = dir->find(dir_name);
            if ((entry != nullptr) && (typeid(*entry).name() == typeid(Directory).name())) {
                dir->remove(dir_name);
            } else {
                std::cout << "no such directory" << std::endl;
            }

        } else {
            std::cout << "no such directory" << std::endl;
        }
    }


    else if (token == "rm") {
        std::string path, dir_name;
        std::getline(iss2, path);
        int last_index = path.find_last_of('/');
        dir_name = path.substr(last_index + 1);

        auto *dir = dynamic_cast<Directory *> (find_directory(root, path.substr(0, last_index)));
        if (dir != nullptr) {
            Entry *entry = dir->find(dir_name);
            if ((entry != nullptr) && (typeid(*entry).name() == typeid(File).name())) {
                dir->remove(dir_name);
            } else {
                std::cout << "no such file" << std::endl;
            }

        } else {
            std::cout << "no such file" << std::endl;
        }
    }
    else{
        std::cout << "Usage:\n"
                     "\t mkdir <path/directoryName>\n"
                     "\t touch <path/fileName>\n"
                     "\t echo <path/fileName> <content>\n"
                     "\t ls <path/directoryName>\n"
                     "\t tree <path/directoryName>\n"
                     "\t cat <path/fileName>\n"
                     "\t mv <path/fileName||directoryName> <destinationPath/directoryName>\n"
                     "\t cp <path/fileName||directoryName> <destinationPath/directoryName>\n"
                     "\t rmdir <path/directoryName>\n"
                     "\t rm <path/fileName>\n" << std::endl;
    }
}

int main() {



    //*****Do NOT MODIFY START*****
    Directory root("root");
    Directory hello("hello");
    Directory world("world");
    world.add(new Directory("hi"));
    hello.add(new Directory(world));
    hello.add(new File("a.txt"));
    root.add(new Directory(hello));
//    root.add(new Directory("hi"));
    std::cout << root
              << std::endl; //this prints all the directories and files in root directory. (the result of tree command)

    std::string inputBuffer;
    while (1) {
        std::getline(std::cin, inputBuffer);
        if (inputBuffer.compare("quit") == 0) break;
        exec_cmd(&root, inputBuffer);
    }
    //*****DO NOT MODIFY END*****

}

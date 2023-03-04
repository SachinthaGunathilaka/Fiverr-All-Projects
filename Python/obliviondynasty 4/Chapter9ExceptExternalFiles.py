filename = input("Enter filename: ")

try:
    with open(filename) as f:
        print("Successfully Opened\n")
        content = f.read()
        print(content)
except IOError as x:
    print("Could not access file")
from os import listdir
from os.path import isfile, join

path = "data"
files = [f for f in listdir(path) if isfile(join(path, f))]

for file in files:
    f = open(path + "/" + file)
    lines = f.readlines()

    for i in range(len(lines)):

        if len(lines[i].strip()) == 0:
            continue

        data = lines[i].strip().split()
        if float(data[8]) < 1.5 and float(data[9]) > 0.9 and float(data[10]) > 0.9:
            data[11] = "-1"

        new_data = ""
        for d in data:
            new_data += d + " "

        lines[i] = new_data + "\n"

    f.close()

    f = open(path + "/" + file, "w")
    for line in lines:
        f.write(line)

    f.close()




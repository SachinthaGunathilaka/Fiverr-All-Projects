import os

if not os.path.exists("Output"):
    os.makedirs("Output")

files = []
for (dirpath, dirnames, filenames) in os.walk("Input"):
    files.extend(filenames)
    break

for file in files:
    if file.endswith(".txt"):

        input_file = "Input/" + file
        output_file = "Output/" + file

        print(input_file)

        f_input = open(input_file)
        lines = f_input.readlines()
        f_input.close()

        f = open(output_file, "w")
        f.write("symbol,datetime,Open,High,Low,Close,Volume\n")

        symbol = "Q_NF1"

        index = 0
        for line in lines:
            index += 1

            line = line.strip()
            if len(line) == 0:
                continue

            if index == 1:
                continue

            data = line.split(",")
            date_list = data[0].split("/")

            for i in range(1, 3):
                if int(date_list[i]) < 10:
                    date_list[i] = "0" + str(date_list[i])

            date = str(date_list[0]) + date_list[1] + date_list[2]
            time = data[1].strip().split(".")[0]
            date_time = date + " " + time

            open_ = data[2].strip()
            high = data[3].strip()
            low = data[4].strip()
            close = data[5].strip()
            volume = data[6].strip()

            f.write(f"{symbol},{date_time},{open_},{high},{low},{close},{volume}\n")

        f.close()


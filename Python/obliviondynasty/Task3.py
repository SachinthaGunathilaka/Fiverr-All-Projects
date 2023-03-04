filename = input()

file = open(filename)
lines = file.readlines()

tv_shows = []
flag = True

count = 0
name = ""
for line in lines:
    line = line.strip()

    if len(line) == 0:
        continue

    if flag:
        count = int(line)

    else:
        name = line
        tv_shows.append([name, count])

    flag = not flag

tv_shows.sort(key=lambda x: (x[1], x[0]))

f = open("outputFile.txt", "w")
for i in range(len(tv_shows)):
    if tv_shows[i][1] < 10:
        f.write(f"0{tv_shows[i][1]}\n")
    else:
        f.write(f"{tv_shows[i][1]}\n")
    f.write(f"{tv_shows[i][0]}\n")



f.close()

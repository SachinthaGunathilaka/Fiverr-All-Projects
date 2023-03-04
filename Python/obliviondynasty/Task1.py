filename = input()
lower_bound = input()
upper_bound = input()

file = open(filename)
lines = file.readlines()
for line in lines:
    line = line.strip()

    if line < lower_bound or line > upper_bound:
        continue
    print(line)


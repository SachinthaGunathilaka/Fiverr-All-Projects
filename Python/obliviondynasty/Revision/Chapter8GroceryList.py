filename = input()

file = open(filename)
lines = file.readlines()

grocery_items = []
flag = True

name = ""
count = 0

for line in lines:
    line = line.strip()

    if flag:
        name = line

    else:
        count = line
        grocery_items.append([name, count])

    flag = not flag

print(grocery_items)
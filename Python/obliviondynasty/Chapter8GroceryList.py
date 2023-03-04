filename = input()

file = open(filename)
lines = file.readlines()

grocery_items = []
flag = True

name = ""
count = ""
completed = True
for line in lines:
    line = line.strip()

    if flag:
        completed = False
        name = line

    else:
        completed = True
        count = line
        grocery_items.append([name, count])

    flag = not flag

if not completed:
    grocery_items.append([name, ""])

print(grocery_items)

with open('CHF 1 NT.csv', 'r', ) as file:
    lines = file.readlines()
    index = 0

    write_file = open("output.csv", "w")
    write_file.write("Date,Description,Montant,Reference\n")
    for i in range(1, len(lines), 2):
        line1 = lines[i].strip().split(";")
        line2 = lines[i+1].strip().split(";")

        write_file.write(line1[0] + ',' + line1[1] + "," + line1[7] + "," + line2[10] + "\n")

    write_file.close()
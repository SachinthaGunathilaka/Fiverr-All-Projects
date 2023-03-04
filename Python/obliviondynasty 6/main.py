from Employee import Employee

hoursPerWeak = {
    'A': 15,
    'B': 12,
    'C': 9,
    'D': 6,
    'F': 0,
}


username = input("Username: ")
emp_id = input("Employee ID: ")
department = input("Department: ")

user = Employee(username, emp_id, department)

username = input("Username of report owner: ")
emp_id = input("Employee ID of report owner: ")
department = input("Department of report owner: ")

report_owner = Employee(username, emp_id, department)




main_menu = """
-------------------------Main Menu-------------------------------

A.	Determine Hours to Study
B.	Determine Grade
C.	Display Averages and Totals
D.	Quit

-----------------------------------------------------------------
"""


# --------------------------- 4   , For A -------------------------------

def optionA():
    studyHours = open("StudyHours.txt", 'r')
    lines = studyHours.readlines()
    studyHours.close()
    # print(lines)

    count = 0
    for i in range(0, len(lines)):
        count += 1
        if count == 1:
            name = lines[i].strip().title()
            lines[i] = name
            continue

        elif count == 2:
            try:
                if int(lines[i].strip()) % 3 != 0:
                    print("Invalid number of credits")
                    tempCredit = (input(f"Enter a valid number of credits for {name}: ")).strip()
                    while int(tempCredit) % 3 != 0:
                        print("Invalid number of credits")
                        tempCredit = (input(f"Enter a valid number of credits for {name}: ")).strip()
                    lines[i] = tempCredit
            except:
                print("Invalid number of credits")
                tempCredit = (input(f"Enter a valid number of credits for {name}: ")).strip()
                while int(tempCredit) % 3 != 0:
                    print("Invalid number of credits")
                    tempCredit = (input(f"Enter a valid number of credits for {name}: ")).strip()
                lines[i] = tempCredit

        elif count == 3:
            if lines[i].strip() not in ['A', 'B', 'C', 'D', 'F']:
                print("Invalid grade")
                tempGrade = (input(f"Enter a valid grade for {name} : ")).strip()
                while tempGrade not in ['A', 'B', 'C', 'D', 'F']:
                    print("Invalid grade")
                    tempGrade = (input(f"Enter a valid grade for {name} : ")).strip()

                lines[i] = tempGrade
            count = 0

    studyHours = open("StudyHours.txt", 'w')
    for line in lines:
        studyHours.write(line.strip() + '\n')

    studyHours.close()
    # -------------------------------------------

    data = []
    count = 0
    temp_data = []

    for line in lines:
        count += 1
        if count == 1:
            print(line.strip())
            temp_data.append(line.strip())
            # HowManyHours.write(line.strip() + '\n')

        elif count == 2:
            print(line.strip())
            temp_data.append(line.strip())
            credit = int(line.strip())
            # HowManyHours.write(line.strip() + '\n')

        elif count == 3:
            hours = int(credit / 3 * hoursPerWeak[line.strip()])
            temp_data.append(hours)

            print(hours)
            # HowManyHours.write(str(hours) + '\n')

            print(line.strip())
            temp_data.append(line.strip())

            # HowManyHours.write(line.strip() + '\n')
            count = 0
            data.append(temp_data)
            temp_data = []

    data.sort(key=lambda x: x[0])

    HowManyHours = open("HowManyHours.txt", 'w')
    for d in data:
        HowManyHours.write(str(d[0]) + "\n")
        HowManyHours.write(str(d[1]) + "\n")
        HowManyHours.write(str(d[2]) + "\n")
        HowManyHours.write(str(d[3]) + "\n")

    HowManyHours.close()


# # ------------------------------- 5 - For B -----------------------------------------------

def optionB():
    Grades = open("Grades.txt", 'r')
    grades = Grades.readlines()
    Grades.close()

    count = 0
    name = ""
    creditValue = 0
    for i in range(0, len(grades)):
        count += 1

        if len(grades[i].strip()) == 0:
            continue
        if count == 1:
            name = grades[i].strip().title()
            grades[i] = name
            continue

        elif count == 2:

            while True:
                try:
                    grades[i] = int(grades[i].strip())
                    if grades[i] % 3 != 0 or grades[i] >= 55:
                        print("Invalid number of credits")
                        tempCredit = int((input(f"Enter a valid number of credits for {name}: ")).strip())
                        while tempCredit % 3 != 0 or tempCredit >= 55:
                            print("Invalid number of credits")
                            tempCredit = int((input(f"Enter a valid number of credits for {name}: ")).strip())
                        grades[i] = tempCredit
                        creditValue = int(grades[i])

                    break

                except:
                    pass

        elif count == 3:
            while True:
                try:
                    grades[i] = int(grades[i])
                    if grades[i] < creditValue or (
                            grades[i] % 15 != 0 and grades[i] % 12 != 0 and grades[i] % 9 != 0 and grades[i] % 6 != 0):
                        print("Invalid Number of Hours ")
                        hours = int(input(f"Enter number of hours to study for {name} : "))
                        while hours < creditValue or (
                                hours % 15 != 0 and hours % 12 != 0 and hours % 9 != 0 and hours % 6 != 0):
                            print("Invalid Number of Hours ")
                            hours = int(input(f"Enter number of hours to study for {name} : "))
                        grades[i] = hours

                    count = 0
                    break

                except:
                    grades[i] = 1
                    pass

    Grades = open("Grades.txt", 'w')
    for line in grades:
        Grades.write(str(line).strip() + '\n')

    Grades.close()

    # -----------------------------

    data = []
    temp_data = []
    count = 0
    for line in grades:
        count += 1
        if count == 1:
            print(str(line).strip())
            temp_data.append(str(line).strip())

        elif count == 2:
            print(str(line).strip())
            credit = int(str(line).strip())
            temp_data.append(str(line).strip())


        elif count == 3:
            print(str(line).strip())
            totHours = int(str(line).strip())
            temp_data.append(str(line).strip())

            gradesValueHour = int((totHours * 3) / credit)
            desiredGrade = 'N'
            for grade in hoursPerWeak:
                if hoursPerWeak[grade] == gradesValueHour:
                    desiredGrade = grade
                    break
            print(desiredGrade)
            temp_data.append(desiredGrade)
            data.append(temp_data)
            temp_data = []

            count = 0

    data.sort(key=lambda x: x[0])
    HowManyHours = open("HowManyHours.txt", 'a')

    for d in data:
        HowManyHours.write(str(d[0]) + "\n")
        HowManyHours.write(str(d[1]) + "\n")
        HowManyHours.write(str(d[2]) + "\n")
        HowManyHours.write(str(d[3]) + "\n")
    HowManyHours.close()

    #

def optionC():
    f = open("HowManyHours.txt")
    lines = f.readlines()

    count = 0
    index = 0
    credits_count = 0
    credit = 0
    hours = 0
    for line in lines:
        print(line)
        if len(line.strip()) == 0:
            continue

        index += 1

        if index == 2:
            credits_count += int(line)
            credit = int(line)

        elif index == 3:
            hours += int(line)

        elif index == 4:
            index = 0
            count += 1


    print(f"\nSTUDY HOURS REPORT\n"
          f"Created for {report_owner.name}\n"
          f"Dept: {report_owner.workingDepartment}")

    print(f"\nCreated By {user.name}\n"
          f"Dept: {user.workingDepartment}")

    print(f"\nTotal Students: {count}")
    print(f"Average Credits: {credits_count/count}")
    print(f"Average Study Hours: {hours/count}")


while True:
    print(main_menu)

    option = input("\nEnter option: ").upper()
    if(option == 'A'):
        optionA()

    elif option == 'B':
        optionB()

    elif option == 'C':
        optionC()

    elif option == 'D':
        break

    else:
        print("Invalid option")



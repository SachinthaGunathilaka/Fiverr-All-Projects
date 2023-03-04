""""
-------------------------------------------------------------------------------

    Name: Your Name
    Student ID: Your Student ID
    COP1047C – Introduction to Python Programming
    Fall 2022 - Th 5:30 PM - 8:50 PM

    Assignment #
    Plagiarism Statement
    I certify that this assignment is my own work and that I have not
    copied in part or whole or otherwise plagiarized the work of other
    students and/or persons.
    I understand that students involved in academic dishonesty will face
    disciplinary sanctions in accordance with the College's Student Rights
    and Responsibilities Handbook (https://www.mdc.edu/rightsandresponsibilities)
    01234567890123456789012345678901234567890123456789012345678901234567890123456789

-------------------------------------------------------------------------------

"""

import os
import sys

index = 0
filename = ""
while index < 3:
    filename = input("\nEnter filename: ")
    if os.path.exists(filename):
        break

    print("File does not exist")
    index += 1

if index == 3:
    print("\nProgram terminating due to invalid filenames!")
    sys.exit(0)


f = open(filename)
lines = f.readlines()

all_details = {}
name = ""

for line in lines:
    line = line.strip()
    try:
        grade = float(line)

        if name != "":
            new_data = all_details[name]
            new_data.append(grade)
            all_details[name] = new_data
    except ValueError:
        name = line.strip()
        all_details[name] = []

for key in all_details.keys():
    print(key, end=" ")
    for grade in all_details[key]:
        print(grade, end=" ")

    if len(all_details[key]) == 0:
        print("0")
    else:
        avg = sum(all_details[key]) / len(all_details[key])
        print(avg)

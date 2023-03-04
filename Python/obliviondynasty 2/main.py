# Display welcome screen
print("---------------------------------------------------")
print("                  WELCOME")
print("---------------------------------------------------")

# Get input for number of students
num_of_stds = input("\nEnter number of students you want to process : ")
# Validate input
while not num_of_stds.isnumeric():
    print("Number of students must be an integer")
    num_of_stds = input("Enter number of students you want to process : ")

# Convert to an integer value
num_of_stds = int(num_of_stds)

study_hours_sum = 0
credits_sum = 0

# Iterate through each student
for i in range(num_of_stds):
    # Get input for name
    first_name = input("\nEnter first name : ").capitalize()
    last_name = input("Enter last name : ").capitalize()

    # Get input for number of credits
    while True:
        try:
            credits = int(input("Number of credits : "))
            # Check whether it is an multiple of 3
            while credits % 3 != 0:
                print("Number of credits must be a multiple of 3")
                credits = int(input("Number of credits : "))

            break

        # If it is not an integer display error message and get input again
        except:
            print("Number of credits must be an positive integer")

    # Get input for grade and validate
    grade = input("Enter the grade that you want : ").upper()
    while grade not in ["A", "B", "C", "D", "F"]:
        print("Invalid grade")
        grade = input("Enter the grade that you want : ").upper()

    # calculate number of classes
    num_of_classes = credits / 3

    # Determine number of study hours for 1 class
    num_of_hours = 0
    if grade == "A":
        num_of_hours = 15

    elif grade == "B":
        num_of_hours = 12

    elif grade == "C":
        num_of_hours = 9

    elif grade == "D":
        num_of_hours = 6

    # Determine number of study hours for all classes
    total_hours = num_of_classes * num_of_hours

    # Calculate summation of total credit and total study hours
    credits_sum += credits
    study_hours_sum += total_hours

    # Display student details
    print(f"\nName: {first_name} {last_name}\n"
          f"Credits: {credits}\n"
          f"Study Hours: {round(total_hours)}\n"
          f"Grade: {grade}")

# Display all students summary
print(f"\nTotal Students: {num_of_stds}\n"
      f"Average Credits: {round(credits_sum / num_of_stds, 2)}\n"
      f"Average Study Hours: {round(credits_sum / num_of_stds, 2)}")

# Global variables
score_sum = 0
count = 0

# Open golf.txt file
file1 = open("golf.txt", "w")


# Function to get input for option
def getOption():
    # Get input from user
    option = input("\nEnter option: ").upper()

    # If it is not valid get input again
    while option not in ["A", "B", "C"]:
        print("Invalid option")
        option = input("Enter option: ").upper()

    return option


# Function to display menu
def displayMenu():
    print("\nA.	Enter Player’s Name and Golf Score\n"
          "B.	Calculates Average Score\n"
          "C.	Exits the program")


# Function to get player details
def getPlayerDetails():
    global score_sum
    global count

    # Get name and score from user
    name = input("\nEnter player name : ")
    score = int(input("Enter player score : "))

    # Validate score input
    while score < 18 or score > 150:
        print("Invalid score")
        score = int(input("Enter player score : "))

    # Write name and score to goal.txt file
    file1.write(f"{name}\t{score}\n")

    # Increment score_sum and count
    score_sum += score
    count += 1


# main function
def main():
    # Display welcome screen
    print("-------------------------------------------------------------")
    print("|         The Springhill Amateur Golf Club Tournament       |")
    print("-------------------------------------------------------------")

    while True:
        # Display menu
        displayMenu()
        # get option from user
        option = getOption()

        # If option is 'A' call getPlayerDetails function
        if option == "A":
            getPlayerDetails()

        # If option is 'B'
        elif option == "B":
            # Calculate average
            average = score_sum / count
            # Display average
            print(f"\nAverage : {round(average, 2)}")

            # Write average to AverageScores.txt file
            file2 = open("AverageScores.txt", "w")
            file2.write(f"Average : {round(average, 2)}\n")
            file2.close()

        # If option is 'C' exit the program
        else:
            break


file1.close()

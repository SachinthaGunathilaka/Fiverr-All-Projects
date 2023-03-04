import matplotlib.pyplot as plt
import matplotlib.image as mpimg


def displayMenu():
    print("\n1) Display all U.S. states\n"
          "2) Search for a specific state\n"
          "3) Bar graph of the top 5 populated states\n"
          "4) Update the state population of a state\n"
          "5) Exit")


def getOption():
    option = int(input("\nEnter option: "))

    if option < 1 or option > 5:
        print("Invalid input")
        option = int(input("\nEnter option: "))

    return option

def readStates(filename):
    f = open(filename)
    lines = f.readlines()
    states = {}
    for line in lines:
        line = line.strip()

        if len(line) == 0:
            continue

        data = line.split(",")
        states[data[0]] = [data[1], int(data[2]), data[3]]

    return states


def displayStates(states):
    print("+----------------------------------------------------------------------------------------+")
    print("| {:<15}| {:<20}| {:<15}| {:<30} |".format("State", "Capital", "Population", "Flower"))
    print("+----------------------------------------------------------------------------------------+")

    for key, value in sorted(states.items()):
        print("| {:<15}| {:<20}| {:<15}| {:<30} |".format(key, value[0], value[1], value[2]))

    print("+----------------------------------------------------------------------------------------+")


def displayStateDetails(state, state_data):
    print("+----------------------------------------------------------------------------------------+")
    print("| {:<15}| {:<20}| {:<15}| {:<30} |".format("State", "Capital", "Population", "Flower"))
    print("+----------------------------------------------------------------------------------------+")

    print("| {:<15}| {:<20}| {:<15}| {:<30} |".format(state, state_data[0], state_data[1], state_data[2]))
    print("+----------------------------------------------------------------------------------------+")

    img = mpimg.imread("images/" + state_data[2] + ".webp")
    imgplot = plt.imshow(img)
    plt.show()


def showBarChart(states):
    states_population = []
    for state in states.keys():
        states_population.append([state, states[state][1]])

    states_population.sort(key=lambda x: x[1], reverse=True)
    top5 = states_population[:5]

    x = [top[0] for top in top5]
    y = [top[1] for top in top5]

    plt.bar(x, y)

    plt.title("Top 5 populated states")

    plt.xlabel("States")
    plt.ylabel("Population")

    plt.show()


states = readStates("state_details.csv")
while True:
    displayMenu()

    option = getOption()
    if option == 1:
        displayStates(states)

    elif option == 2:
        input_state = input("Enter state: ").capitalize()
        if input_state in states.keys():
            displayStateDetails(input_state, states[input_state])

        else:
            print("Input state is not valid!")


    elif option == 3:
        showBarChart(states)

    elif option == 4:
        input_state = input("Enter state: ").capitalize()
        while input_state not in states.keys():
            print("Invalid state!")
            input_state = input("Enter state: ").capitalize()

        new_population = int(input("Enter new population: "))

        new_data = states[input_state]
        new_data[1] = new_population
        states[input_state] = new_data

        print("Updated the new population!")

    else:
        break

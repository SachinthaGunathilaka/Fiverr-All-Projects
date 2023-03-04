import random

# Glocal variables to store data about the game
deck_position = 10
show = False
hidden_card_select = False
selected_grid_card = -1
deck = []
grid = []


# Function to check whether the game is over
def isOver():
    # Iterate through each cell
    for cell in grid:
        # If at least one cell is not filled return True
        if cell == -1:
            return False
    return True


# Function to get the all the cards with their actual names
def getDeckWithNames():
    types = ["S", "H", "C", "D"]
    values = ["A", "K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2"]

    deck = []
    for value in values:
        for type in types:
            deck.append(value + type)
    return deck


# Function to get shuffled deck of cards
def getShuffledDeck():
    # add 1 to 52 numbers to the deck
    deck = []
    for i in range(52):
        deck.append(i)

    # Shuffled the deck according to the given algorithm
    n = 51
    for i in range(51, -1, -1):
        swap_pos = int(random.random() * n)
        swap_el = deck[swap_pos]

        deck[swap_pos] = deck[i]
        deck[i] = swap_el
        n -= 1

    return deck


# Function to show the hidden card
def showCard():
    global show
    global hidden_card_select
    global selected_grid_card

    # Set show to True
    show = True

    # Invert the hidden_card_select value
    hidden_card_select = not hidden_card_select

    # Set selected_grid_card to -1
    selected_grid_card = -1

    # Execute the displayGame function
    displayGame()


# Function to display control section of the game
def displayControlSection():
    html_text = "<table id='table1'><tr>"

    for j in range(3):
        # Display restart button
        if j == 0:
            html_text += """<td id='res_button'> <button onclick='init()' style = 'font-size:15px;' type="button">Restart Game</button> </td>"""
        if j == 1:
            # Hidden card (face down)
            url = "\'http://codeboot.org/cards/back.svg\'"

            # Face up the hidden card
            if show:
                url = "\'http://codeboot.org/cards/" + getDeckWithNames()[deck[deck_position]] + ".svg\'"

            # Change the background color according to the hidden_card_select value
            color = 'transparent'
            if hidden_card_select:
                color = 'lime'

            html_text += "<td style='background-color:" + color + "\'" + "id='back_card'><img onclick='showCard()' src=" + url + "></td>"
            # print("<td style='background-color:" + color + "\'" +  "id='back_card'><img onclick='showCard()' src=" + url  + "></td>")
            card = document.querySelector("#table1 tr:nth-child(1) td:nth-child(3)")

        else:
            # To display empty space
            html_text += "<td></td>"

    html_text += "</tr></table>"
    return html_text


# This function will execute when a card is clicked
def clickGrid(position):
    global hidden_card_select
    global deck
    global deck_position
    global grid
    global selected_grid_card
    global show

    # If the clicked card in not an empty slot and there is no highlighted card then
    # Highlight the selected card

    if grid[position] != -1 and selected_grid_card == -1:
        selected_grid_card = position
        hidden_card_select = False

    # If the clicked card is the highlighted card then unselect that card
    elif grid[position] != -1 and selected_grid_card == position:
        selected_grid_card = -1

    # If the clicked card in not an empty slot and there exists a highlighted card then
    # Swap these 2 cards
    elif selected_grid_card != -1 and selected_grid_card != position:
        temp = grid[position]
        grid[position] = grid[selected_grid_card]
        grid[selected_grid_card] = temp
        selected_grid_card = -1

    # If the clicked card is an empty slot and hidden card is already selected then
    # Put the hidden card into that empty slot
    elif hidden_card_select and grid[position] == -1:
        grid[position] = deck[deck_position]
        deck_position += 1
        hidden_card_select = False
        show = False

    displayGame()


# Function to display the grid of cards
def displayGrid():
    global grid
    global selected_grid_card

    # Generate scores list
    scores = generateScoreList()
    total_score = 0

    # Calculate total score
    for score in scores:
        total_score += score

    # Get names of the cards
    card_names = getDeckWithNames()
    html_text = "<table id='table2'>"

    for i in range(6):
        html_text += "<tr>"
        for j in range(6):
            if i != 5 and j == 5:
                # Display scores of each row
                if scores[i] != 0:
                    html_text += "<td> <h3>" + str(scores[i]) + "</h3> </td>"
                # Display empty slot
                else:
                    html_text += "<td> </td>"
                continue

            if i == 5 and j != 5:
                # Diplay scores of each column
                if scores[5 + j] != 0:
                    html_text += "<td> <h3>" + str(scores[5 + j]) + "</h3> </td>"
                # Display empty slot
                else:
                    html_text += "<td> </td>"
                continue
            if i == 5 and j == 5:
                # Display total score
                if total_score != 0:
                    html_text += "<td> <h3>" + str(total_score) + "</h3> </td>"
                # Display empty slot
                else:
                    html_text += "<td> </td>"
                continue
            postion = i * 5 + j
            # if deck_position > i*5 + j:

            # Set the background color
            color = 'transparent'
            if selected_grid_card == postion:
                # Highlight the selected card
                color = 'lime'

            # Display card
            if grid[i * 5 + j] != -1:
                url = "\'http://codeboot.org/cards/" + card_names[grid[i * 5 + j]] + ".svg\'"
                id = str(i * 5 + j) + "\'"
                html_text += "<td style='background-color:" + color + "\'" + " id=\'" + id + "><img onclick='clickGrid(" + str(
                    postion) + ")\' src=" + url + "></td>"
            # Display empty slot
            else:
                html_text += "<td><img onclick='clickGrid(" + str(
                    postion) + ")\' src='http://codeboot.org/cards/empty.svg'></td>"

        html_text += "</tr>"
    html_text += "</table>"
    return html_text


# Function to display the game
def displayGame():
    # Generate scores list
    scores = generateScoreList()
    total_score = 0
    # Calculate total score
    for score in scores:
        total_score += score

    # If the game is over
    if isOver():
        alert("Your final score is " + str(total_score))
        init()

    # Display the game using html
    main = document.querySelector('#main')

    url = "http://codeboot.org/cards/10D.svg"
    html_text = """
      <style>
        #main table td { border: none; padding: 1px 2px; }
        #main table td img { height: auto; }
        #res_button{
        color:'red'
        }
      </style>
      """

    # Display control section of the game
    html_text += displayControlSection()
    # Display the grid of cards
    html_text += displayGrid()
    main.innerHTML = html_text


# Function to categorize each card according to the suit
def suitCategorizer(hand):
    suits = []

    # Add 4 empty arrays to suits
    for i in range(4):
        suits.append([])

    # Add each card to relevant array
    for card in hand:
        suits[card % 4].append(card // 4)

    return suits


# Function to categorize each card according to the value
def valuesCategorizer(hand):
    values = []

    # Add 13 empty arrays to suits
    for i in range(13):
        values.append([])

    # Add each card to relevant array
    for card in hand:
        values[card // 4].append(card % 4)

    return values


# Function to sort a given array
def sortList(arr):
    n = len(arr)

    # Sort the array using bubble sort
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp

    return arr


# Function to calculate score of a given hand
def calculateScore(hand):
    # Sort the hand
    hand = sortList(hand)
    # call suitCategorizer
    suits = suitCategorizer(hand)
    # call valuesCategorizer
    values = valuesCategorizer(hand)

    # Check for Royal Flush
    for suit in suits:
        if suit == [0, 1, 2, 3, 4]:
            return 100

    # Check for Straight Flush
    straight_flush = True
    for suit in suits:
        straight_flush = True

        if len(suit) != 5:
            continue

        for i in range(4):
            if suit[i] + 1 != suit[i + 1]:
                straight_flush = False
                break

        if straight_flush:
            return 75

    # Check for Square
    for value in values:
        if len(value) == 4:
            return 50

    # Check for Full House
    three = False
    two = False
    for value in values:
        if len(value) == 3:
            three = True
        elif len(value) == 2:
            two = True
    if three and two:
        return 25

    # Check for ColorWhereFlush
    for suit in suits:
        if len(suit) == 5:
            return 20

    # Check for Fifth
    temp_values = []
    for val in values:
        temp_values.append(val)

    temp_values.append(values[0])
    count = 0

    for i in range(len(temp_values)):
        if count == 5:
            return 15
        if count != 0 and len(temp_values[i]) == 0:
            break

        if len(temp_values[i]) != 0:
            count += 1

    if count == 5:
        return 15

    count = 0
    for i in range(len(temp_values) - 4, len(temp_values)):
        if len(temp_values[i]) != 0:
            count += 1

    if count == 4 and len(values[0]) != 0:
        return 15

    # Check for three of a kind
    for value in values:
        if len(value) == 3:
            return 10

    # Check for Dual Pair
    pairs = 0
    for value in values:
        if len(value) == 2:
            pairs += 1

    if pairs == 2:
        return 5

    # Check for A Pair
    if pairs == 1:
        return 2
    return 0


# Function to generate hands (Each row and column is considered as a hand)
def generateHands():
    hands = []

    row = []

    # Add each row to hands list
    for i in range(25):
        if i != 0 and i % 5 == 0:
            hands.append(row)
            row = []

        if grid[i] != -1:
            row.append(grid[i])
    hands.append(row)

    # Add each column to hands list
    for i in range(5):
        col = []
        for j in range(i, 25, 5):
            if grid[j] != -1:
                col.append(grid[j])
        hands.append(col)

    return hands


# Function to calculate scores of each hand
def generateScoreList():
    # Call generateHands function to get list of hands
    hands = generateHands()
    scores = []

    # Iterate through each hand and calculate score for each hand
    for hand in hands:
        score = calculateScore(hand)
        scores.append(score)
    return scores


# Init function
def init():
    global deck
    global show
    global hidden_card_select
    global grid
    global selected_grid_card

    # Reset the game
    selected_grid_card = -1
    grid = []
    for i in range(25):
        grid.append(-1)
    show = False
    hidden_card_select = False

    # Call getShuffledDeck to get shuffled deck
    deck = getShuffledDeck()

    # Display the game
    displayGame()


# Function for testing
def test():
    # Test calculate score method
    assert calculateScore([0, 4, 8, 12, 16]) == 100
    assert calculateScore([2, 6, 10, 14, 18]) == 100

    assert calculateScore([10, 14, 18, 22, 26]) == 75
    assert calculateScore([13, 17, 21, 25, 29]) == 75

    assert calculateScore([0, 1, 3, 2]) == 50
    assert calculateScore([28, 31, 30, 29]) == 50

    assert calculateScore([0, 1, 3, 11, 10]) == 25
    assert calculateScore([32, 34, 8, 10, 11]) == 25

    assert calculateScore([0, 12, 24, 8, 40]) == 20
    assert calculateScore([9, 21, 13, 33, 5]) == 20

    assert calculateScore([10, 15, 19, 27, 22]) == 15
    assert calculateScore([2, 49, 44, 40, 38]) == 15
    assert calculateScore([2, 7, 8, 13, 18]) == 15

    assert calculateScore([21, 23, 22, 7]) == 10
    assert calculateScore([32, 34, 32]) == 10

    assert calculateScore([2, 3, 42, 40]) == 5
    assert calculateScore([18, 19, 2, 1, 38]) == 5

    assert calculateScore([40, 42]) == 2
    assert calculateScore([2, 10, 39, 7, 9]) == 2


test()
init()
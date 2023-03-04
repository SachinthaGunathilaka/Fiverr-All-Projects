import random

deck_position = 10
show = False
hidden_card_select = False
selected_grid_card = -1
deck = []
grid = []


def isOver():
    if grid[4] != -1:
        return True

    return False
    for cell in grid:
        if cell == -1:
            return False
    return True


def getDeckWithNames():
    types = ["S", "H", "C", "D"]
    values = ["A", "K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2"]

    deck = []
    for value in values:
        for type in types:
            deck.append(value + type)
    return deck


def getShuffledDeck():
    deck = []
    for i in range(52):
        deck.append(i)

    n = 51
    for i in range(51, -1, -1):
        swap_pos = int(random.random() * n)
        swap_el = deck[swap_pos]

        deck[swap_pos] = deck[i]
        deck[i] = swap_el
        n -= 1

    return deck


def showCard():
    global show
    global hidden_card_select
    global selected_grid_card

    show = True
    hidden_card_select = not hidden_card_select
    selected_grid_card = -1
    displayGame()


def displayControlSection():
    html_text = "<table id='table1'><tr>"

    for j in range(3):
        if j == 0:
            html_text += """<td id='res_button'> <button onclick='init()' style = 'font-size:15px;' type="button">Restart Game</button> </td>"""
        if j == 1:
            url = "\'http://codeboot.org/cards/back.svg\'"
            if show:
                url = "\'http://codeboot.org/cards/" + getDeckWithNames()[deck[deck_position]] + ".svg\'"
            # url = "\'http://codeboot.org/cards/2S.svg\'"
            color = 'transparent'
            if hidden_card_select:
                color = 'lime'

            html_text += "<td style='background-color:" + color + "\'" + "id='back_card'><img onclick='showCard()' src=" + url + "></td>"
            # print("<td style='background-color:" + color + "\'" +  "id='back_card'><img onclick='showCard()' src=" + url  + "></td>")
            card = document.querySelector("#table1 tr:nth-child(1) td:nth-child(3)")


        else:
            html_text += "<td></td>"

    html_text += "</tr></table>"
    return html_text


def clickGrid(position):
    global hidden_card_select
    global deck
    global deck_position
    global grid
    global selected_grid_card
    global show

    if grid[position] != -1 and selected_grid_card == -1:
        selected_grid_card = position
        hidden_card_select = False

    elif grid[position] != -1 and selected_grid_card == position:
        selected_grid_card = -1

    elif selected_grid_card != -1 and selected_grid_card != position:
        temp = grid[position]
        grid[position] = grid[selected_grid_card]
        grid[selected_grid_card] = temp
        selected_grid_card = -1


    elif hidden_card_select and grid[position] == -1:
        grid[position] = deck[deck_position]
        deck_position += 1
        hidden_card_select = False
        show = False

    displayGame()


def displayGrid():
    global grid
    global selected_grid_card

    scores = generateScoreList()
    total_score = 0
    for score in scores:
        total_score += score

    card_names = getDeckWithNames()
    html_text = "<table id='table2'>"

    for i in range(6):
        html_text += "<tr>"
        for j in range(6):
            if i != 5 and j == 5:
                if scores[i] != 0:
                    html_text += "<td> <h3>" + str(scores[i]) + "</h3> </td>"
                else:
                    html_text += "<td> </td>"
                continue

            if i == 5 and j != 5:
                if scores[5 + j] != 0:
                    html_text += "<td> <h3>" + str(scores[5 + j]) + "</h3> </td>"
                else:
                    html_text += "<td> </td>"
                continue
            if i == 5 and j == 5:
                if total_score != 0:
                    html_text += "<td> <h3>" + str(total_score) + "</h3> </td>"
                else:
                    html_text += "<td> </td>"
                continue
            postion = i * 5 + j
            # if deck_position > i*5 + j:

            color = 'transparent'
            if selected_grid_card == postion:
                color = 'lime'

            if grid[i * 5 + j] != -1:
                url = "\'http://codeboot.org/cards/" + card_names[grid[i * 5 + j]] + ".svg\'"
                id = str(i * 5 + j) + "\'"
                html_text += "<td style='background-color:" + color + "\'" + " id=\'" + id + "><img onclick='clickGrid(" + str(
                    postion) + ")\' src=" + url + "></td>"
            else:
                html_text += "<td><img onclick='clickGrid(" + str(
                    postion) + ")\' src='http://codeboot.org/cards/empty.svg'></td>"

        html_text += "</tr>"
    html_text += "</table>"
    return html_text


def displayGame():
    scores = generateScoreList()
    total_score = 0
    for score in scores:
        total_score += score

    if isOver():
        alert("Your final score is " + str(total_score))
        init()
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
    html_text += displayControlSection()
    html_text += displayGrid()
    main.innerHTML = html_text


# def calculateScore(hand):
# all(card == 0 for card in hand)


def suitCategorizer(hand):
    suits = []

    for i in range(4):
        suits.append([])

    names = getDeckWithNames()

    for card in hand:
        suits[card % 4].append(card // 4)

    return suits


def valuesCategorizer(hand):
    values = []

    for i in range(13):
        values.append([])

    names = getDeckWithNames()

    for card in hand:
        values[card // 4].append(card % 4)

    return values


def sortList(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp

    return arr


def calculateScore(hand):
    hand = sortList(hand)
    suits = suitCategorizer(hand)

    values = valuesCategorizer(hand)
    # Royal Flush
    for suit in suits:
        if suit == [0, 1, 2, 3, 4]:
            return 100

    # Straight Flush
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

    # Square
    for value in values:
        if len(value) == 4:
            return 50

    # Full House
    three = False
    two = False
    for value in values:
        if len(value) == 3:
            three = True
        elif len(value) == 2:
            two = True
    if three and two:
        return 25

    # ColorWhereFlush
    for suit in suits:
        if len(suit) == 5:
            return 20

    # Fifth
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

    # three of a kind
    for value in values:
        if len(value) == 3:
            return 10

    # Dual Pair
    pairs = 0
    for value in values:
        if len(value) == 2:
            pairs += 1

    if pairs == 2:
        return 5

    # A Pair
    if pairs == 1:
        return 2
    return 0


def generateHands():
    hands = []

    row = []
    for i in range(25):
        if i != 0 and i % 5 == 0:
            hands.append(row)
            row = []

        if grid[i] != -1:
            row.append(grid[i])
    hands.append(row)

    for i in range(5):
        col = []
        for j in range(i, 25, 5):
            if grid[j] != -1:
                col.append(grid[j])
        hands.append(col)

    return hands


def generateScoreList():
    hands = generateHands()
    scores = []
    for hand in hands:
        score = calculateScore(hand)
        scores.append(score)
    return scores


def init():
    global deck
    global show
    global hidden_card_select
    global grid
    global selected_grid_card

    selected_grid_card = -1
    grid = []
    for i in range(25):
        grid.append(-1)

    show = False
    hidden_card_select = False
    deck = getShuffledDeck()

    displayGame()

    # suits = suitCategorizer([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
    # values = valueCategorizer([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
    # print(values)

    print(getDeckWithNames())
    # score = calculateScore([1, 5, 9, 13, 17])
    # score = calculateScore([9, 13, 17, 21, 25])
    # score = calculateScore([7, 6, 9, 5, 4])

    # score = calculateScore([0, 1, 2, 4, 6])
    # score = calculateScore([4, 8, 12, 20, 28])

    # score = calculateScore([4, 8, 12, 20, 28])

    # score = calculateScore([5, 10, 12, 19, 3])
    # score = calculateScore([49, 46, 41, 39, 32])
    # score = calculateScore([0, 4, 8, 13, 19])
    # score = calculateScore([33, 29, 25, 22, 19])
    # score = calculateScore([49, 46, 41, 39, 2])

    # score = calculateScore([4, 5, 7, 9, 22])
    # score = calculateScore([4, 7, 21, 22, 35])

    # score = calculateScore([4, 7, 21, 40, 35])
    # print(score)

    generateScoreList()


init()

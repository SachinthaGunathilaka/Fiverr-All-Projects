import functools


# Function to read csv file from the given path
def readCSV(path):
    # Read csv file and split by new line character
    # lines = readFile(path).split('\n')
    lines = open(path).readlines()

    # If the last line is empty remove that
    if lines[-1] == '': lines.pop()
    # Split each line by comma
    return list(map(lambda line: line.split(','), lines))


# Function to remove unwanted spaces and newline chars
def cleanData(data):
    # Iterate through each element in the 2D array and call strip() function
    return list(map(lambda row: list(map(lambda cell: cell.strip(), row)), data))


# Function to get the maximum widths of each column
def getMaxWidthCols(data):
    return list(map(lambda index: max(list(map(lambda row: len(row[index]), data))), range(len(data[0]))))


# Function to generate row of symbols ('+' and '-')
def generateGridRow(data):
    # Call getMaxWidthCols function to find maximum widths of each column
    widths = getMaxWidthCols(data)

    # Generate list of symbols
    gridRow = list(map(lambda index: '+' + widths[index] * '-', range(len(data[0]))))

    # Concatenate the list and return it
    return functools.reduce(lambda a, b: a + b, gridRow) + '+'


# Function to generate text of a cell with relevant spacing
def generateTextCell(text, widths, index):
    return '|' + ' ' * (widths[index] - len(text)) + text


# Function to generate row with texts
def generateTextRow(data, rowIndex):
    # Call generateGridRow to generate row of grid
    gridRow = generateGridRow(data)

    # Call getMaxWidthCols to get maximum width of each column
    widths = getMaxWidthCols(data)

    # Generate row with texts
    rowText = list(map(lambda index: generateTextCell(data[rowIndex][index], widths, index), range(len(data[0]))))

    # Add new line character for each row except the last row
    if rowIndex == len(data) - 1:
        return gridRow + "\n" + functools.reduce(lambda a, b: a + b, rowText) + '|'
    return gridRow + "\n" + functools.reduce(lambda a, b: a + b, rowText) + '|\n'


# Function to read csv file in the given path and generate formatted text
def grilleCSV(path):
    # Read csv file
    originalData = readCSV("input.csv")
    # Call cleanData to remove unwanted spaces and newlines from the csv file data
    cleanedData = cleanData(originalData)

    # Generate formatted text
    allText = list(map(lambda index: generateTextRow(cleanedData, index), range(len(cleanedData))))
    return functools.reduce(lambda a, b: a + b, allText) + "\n" + generateGridRow(cleanedData)


# Function for unit testing
def unitTests():
    data1 = [['Surname', 'First name', 'Assignment #1', 'Assignment #2', 'Assignment #3'],
             ['Deutsch', 'David', '100', '100', '100'],
             ['Diaz', 'Manual', '85', '99', '78']]

    data2 = [['Surname', 'First name', 'Assignment #1', 'Assignment #2', 'Assignment #3'],
             ['Deutsch', 'David', '100', '100', '100'],
             ['Alexandro', 'Manual', '85', '99', '78']]

    # Test cleanData function
    cleanedData = cleanData([[' surname ', 'firstname\n'], ['Deutsch', 'David\n']])
    assert cleanedData == [['surname', 'firstname'], ['Deutsch', 'David']]

    cleanedData = cleanData([['surname\n', 'firstname\n '], ['Deutsch ', 'David\n']])
    assert cleanedData == [['surname', 'firstname'], ['Deutsch', 'David']]

    # Test getMaxWidthCols function
    max_widths = getMaxWidthCols(data1)
    assert max_widths == [7, 10, 13, 13, 13]

    max_widths = getMaxWidthCols(data2)
    assert max_widths == [9, 10, 13, 13, 13]

    # Test generateGridRow function
    gridRow = generateGridRow(data1)

    assert gridRow == "+-------+----------+-------------+-------------+-------------+"

    gridRow = generateGridRow(data2)

    assert gridRow == "+---------+----------+-------------+-------------+-------------+"

    # Test generateTextCell function
    widths = getMaxWidthCols(data1)

    cellText = generateTextCell("Diaz", widths, 0)
    assert cellText == "|   Diaz"

    cellText = generateTextCell("Deutsch", widths, 0)
    assert cellText == "|Deutsch"

    cellText = generateTextCell("100", widths, 2)
    assert cellText == "|          100"

    # Test generateTextRow function
    rowText = generateTextRow(data1, 0)
    assert rowText == "+-------+----------+-------------+-------------+-------------+\n" \
                      "|Surname|First name|Assignment #1|Assignment #2|Assignment #3|\n"

    rowText = generateTextRow(data1, 2)
    assert rowText == "+-------+----------+-------------+-------------+-------------+\n" \
                      "|   Diaz|    Manual|           85|           99|           78|"


# Call unitTests function
unitTests()


# Call grilleCSV function
text = grilleCSV("input.csv")
print(text)


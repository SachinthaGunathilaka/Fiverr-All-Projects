# Function to convert row in csv to a specific type
def rowToLine(row):

    # Extract start position and put it into a struct
    start = struct(x=int(row[0]), y=int(row[1]))
    # Extract end position and put it into a struct
    end = struct(x=int(row[2]), y=int(row[3]))
    # Extract color details and put it into a struct
    color = struct(r=int(row[4]), g=int(row[5]), b=int(row[6]))
    # Put all the data into one struct
    result =  struct(start = start, end = end, color = color, thickness=int(row[7]))
    return result


# Function to draw a line
def drawLine(line):
    # Hide the tkinter
    ht()
    # Pen up
    pu()
    # Set the thickness of the pen
    pensize(line.thickness)
    # Set pen color
    pencolor(line.color.r/15, line.color.g/15, line.color.b/15)
    # Go to the initial position
    goto(line.start.x, line.start.y)

    # Pen down
    pd()
    # Draa line from start position to end position
    goto(line.end.x, line.end.y)
    

# Function to convert csv data into a drawing
def draw():

    # Read the csv file
    import data
    rows = data.tree.split("\n")

    # Iterate through each row
    for row in rows:
        # Skip empty rows
        if len(row) == 0:
            continue

        # Split the data in the row by commas
        data = row.split(",")

        # Convert row into a specific format (line)
        line = rowToLine(data)
        # Draw the line
        drawLine(line)

# Call draw function
draw()


# Function to unit testing
def unitTests():
    # Check rowToLine function
    struct1 = struct(start=struct(x=-20, y=70), end=struct(x=-20, y=-70), color=struct(r=15, g=0, b=0), thickness=5)
    func_result1 = rowToLine(["-20","70","-20","-70","15","0","0","5"])
    assert str(func_result1) == str(struct1)
    
    
    struct2 = struct(start=struct(x=10, y=20), end=struct(x=-20, y=-50), color=struct(r=7, g=8, b=0), thickness=10)
    func_result2 = rowToLine(["10","20","-20","-50","7","8","0","10"])
    assert str(func_result2) == str(struct2)
    
    struct3 = struct(start=struct(x=30, y=12), end=struct(x=-14, y=-23), color=struct(r=9, g=7, b=14), thickness=8)
    func_result3 = rowToLine(["30","12","-14","-23","9","7","14","88"])
    assert str(func_result3) == str(struct3)
    
    
    line1 = rowToLine(["-20","70","-20","-70","15","0","0","5"])
    drawLine(line1)

    line2 = rowToLine(["-50", "0", "50", "0", "0", "0", "0", "100"])
    drawLine(line2)

    line3 = rowToLine(["20","70","20","-70","0","15","0","5"])
    drawLine(line3)


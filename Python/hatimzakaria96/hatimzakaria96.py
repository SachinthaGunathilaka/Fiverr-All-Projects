# Import tuiles file (It contains colormap and images)
import tuiles

# Import libraries
import time
import random
import math

# DisplayImage function
def DisplayImage(x, y, colormap, image):
    # Iterate through each row
    for i in range(len(image)):
        # Iterate through each element in the row
        for j in range(len(image[0])):
            # Set pixel at the relevant coordinate according to the given image
            setPixel(y*16 + j,x*16 + i, colormap[image[i][j]])

# DisplayTile function
def DisplayTile(x, y, tile):
    # Call DisplayImage method to display given tile
    DisplayImage(x, y, tuiles.colormap, tuiles.images[tile])

# WaitClick function
def WaitClick():
    # Infinite loop
    while True:
        # wait 0.01 seconds
        time.sleep(0.01)
        # get details of the current mouse pointer
        mouse = getMouse()
        # If the mouse is released
        if mouse.button == 0:
            # Infinite loop
            while True:
                # wait 0.01 seconds
                time.sleep(0.01)
                # get details of the current mouse pointer
                mouse = getMouse()
                # If the mouse is clicked
                if mouse.button == 1:
                    # return the position of the mouse (x and y coordinates)
                    return (mouse.y//16, mouse.x//16)


# PermutationRandom function
def PermutationRandom(n):
    # Define empty array to hold random numbers
    random_numbers = []
    # Fill random_numbers array by numbers from 0 to n-1
    for i in range(n):
        random_numbers.append(i)

    # Loop runs n times
    for i in range(n):
        # generate random number between i and n-1
        index = int(i + random.random() * (n-i))

        # Swap numbers in 'i' and 'index' position
        temp = random_numbers[index]
        random_numbers[index] = random_numbers[i]
        random_numbers[i] = temp

    # Return random_numbers
    return random_numbers


# Inversions function
def Inversions(tab, x):
    # Initialize flag to False and count to 0
    flag = False
    count = 0

    # Iterate through tab array
    for element in tab:
        # If the current element in the tab array is x
        if x == element:
            # Set flag to True
            flag = True

        # If the flag is True and current element is smaller than x increment the count by 1
        if flag and element != 0 and (x > element):
            count += 1

    # Return count
    return count


# Soluble function
def Soluble(tab):
    # Initialize sum and i to 0
    sum = 0
    i = 0

    # Iterate through tab array
    for element in tab:
        # If the current element is 0
        if element == 0:
            # Increment sum by row index (Row indices starts from 0)
            sum += i//math.sqrt(len(tab)) + 1

        # If the current element is not 0
        else:
            # Increment sum by inversion of the element
            sum += Inversions(tab, element)

        # Increment i by 1 (i is used to finding the index of the current element)
        i += 1

    # If sum is even return True, otherwise False
    return sum % 2 == 0


# Initial function
def Initial(width):
    # Call PermutationRandom() function to get random_numbers
    random_numbers = PermutationRandom(width*width)

    # while the random_numbers array is not soluble
    while not Soluble(random_numbers):
        # call PermutationRandom() function to generate random numbers again
        random_numbers = PermutationRandom(width*width)
    
    return random_numbers


# taquin function
def taquin(width):
    # Set screen mode
    setScreenMode(width*16,width*16)

    # call Initial function
    grid = Initial(width)

    # Infinite loop
    while True:
        # Display each tile in the window
        for i in range(len(grid)):
            DisplayTile(i//width, i%width, grid[i])

        # Initially set is_win to True
        is_win = True

        # Iterate though each value in the grid
        for i in range(len(grid)-2):
            # If the current value is 0, check whether it is in bottom right corner
            if grid[i] == 0:
                # If it is not in the bottom right corner return False
                if(i != width*width-1):
                    is_win = False

            # If the current value is not 0, check whether they are in ascending order
            else:
                # If not return False
                if(grid[i] >  grid[i+1]):
                    is_win = False

        # If the play has won the game.
        if is_win:
            # Alert a message
            alert("You won the game!")
            # Restart the game
            grid = Initial(width)
            continue
            
            
        # get index of the zero value
        zero = grid.index(0)

        # get user click coordinates
        (x, y) = WaitClick()
        index = x*width + y

        # Check whether it is a valid move
        valid_move = (index == zero+1 or index == zero-1) and (zero//width == index//width)
        valid_move = valid_move or (index == zero - width) or (index == zero + width)
        # If it is a valid move
        if valid_move:
            # swap clicked grid with the 0 grid
            grid[zero] = grid[index]
            grid[index] = 0
    

# testTaquin function
def testTaquin():
    setScreenMode(16,16)

    # Testing DisplayImage function
    DisplayImage(0, 0, tuiles.colormap, tuiles.images[1])
    img1_grid = "#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#ccc\n\
#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#ccc#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#ccc#888#888#888#888#888#888#888#888#888#888#888#888#888#888\n\
#ccc#888#888#888#888#888#888#888#888#888#888#888#888#888#888#888"

    assert img1_grid == exportScreen()
    
    
    DisplayImage(0, 0, tuiles.colormap, tuiles.images[2])
    img2_grid = "#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#ccc\n\
#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#ccc#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#080#080#080#080#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#080#080#080#080#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#080#080#080#080#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#080#080#080#080#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#080#080#ccc#ccc#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#080#080#ccc#ccc#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#080#080#080#080#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#080#080#080#080#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#ccc#888#888#888#888#888#888#888#888#888#888#888#888#888#888\n\
#ccc#888#888#888#888#888#888#888#888#888#888#888#888#888#888#888"

    assert img2_grid == exportScreen()

    DisplayImage(0, 0, tuiles.colormap, tuiles.images[3])
    img3_grid = "#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#ccc\n\
#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#ccc#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#080#080#080#080#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#080#080#080#080#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#080#080#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#080#080#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#080#080#080#080#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#080#080#080#080#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#ccc#888#888#888#888#888#888#888#888#888#888#888#888#888#888\n\
#ccc#888#888#888#888#888#888#888#888#888#888#888#888#888#888#888"
    assert img3_grid == exportScreen()
    
    
    DisplayImage(0, 0, tuiles.colormap, tuiles.images[4])
    img4_grid = "#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#ccc\n\
#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#ccc#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#080#080#ccc#ccc#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#080#080#ccc#ccc#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#080#080#ccc#ccc#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#080#080#ccc#ccc#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#080#080#080#080#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#080#080#080#080#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#080#080#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#ccc#888#888#888#888#888#888#888#888#888#888#888#888#888#888\n\
#ccc#888#888#888#888#888#888#888#888#888#888#888#888#888#888#888"

    assert img4_grid == exportScreen()
    
    
    DisplayImage(0, 0, tuiles.colormap, tuiles.images[15])
    img15_grid = "#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#ccc\n\
#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#fff#ccc#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#080#080#ccc#ccc#080#080#080#080#080#080#ccc#888#888\n\
#fff#fff#ccc#080#080#ccc#ccc#080#080#080#080#080#080#ccc#888#888\n\
#fff#fff#ccc#080#080#ccc#ccc#080#080#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#080#080#ccc#ccc#080#080#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#fff#ccc#080#080#ccc#ccc#080#080#080#080#080#080#ccc#888#888\n\
#fff#fff#ccc#080#080#ccc#ccc#080#080#080#080#080#080#ccc#888#888\n\
#fff#fff#ccc#080#080#ccc#ccc#ccc#ccc#ccc#ccc#080#080#ccc#888#888\n\
#fff#fff#ccc#080#080#ccc#ccc#ccc#ccc#ccc#ccc#080#080#ccc#888#888\n\
#fff#fff#ccc#080#080#ccc#ccc#080#080#080#080#080#080#ccc#888#888\n\
#fff#fff#ccc#080#080#ccc#ccc#080#080#080#080#080#080#ccc#888#888\n\
#fff#fff#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#ccc#888#888\n\
#fff#ccc#888#888#888#888#888#888#888#888#888#888#888#888#888#888\n\
#ccc#888#888#888#888#888#888#888#888#888#888#888#888#888#888#888"
    assert img15_grid == exportScreen()
    
    
    # Testing DisplayTile function
    DisplayTile(0, 0, 1)
    assert img1_grid == exportScreen()
    
    DisplayTile(0, 0, 2)
    assert img2_grid == exportScreen()

    DisplayTile(0, 0, 3)
    assert img3_grid == exportScreen()
    
    
    DisplayTile(0, 0, 4)
    assert img4_grid == exportScreen()
    
    
    DisplayTile(0, 0, 15)
    assert img15_grid == exportScreen()
    
    
    # Test permutationRandom function
    random_numbers = PermutationRandom(10)
    assert len(random_numbers) == 10
    isValid = True
    for i in range(10):
        if i not in random_numbers:
            isValid = False
            break 
    assert isValid == True
    
    
    random_numbers = PermutationRandom(5)
    assert len(random_numbers) == 5
    isValid = True
    for i in range(5):
        if i not in random_numbers:
            isValid = False
            break 
    assert isValid == True
    
    
    random_numbers = PermutationRandom(100)
    assert len(random_numbers) == 100
    isValid = True
    for i in range(100):
        if i not in random_numbers:
            isValid = False
            break 
    assert isValid == True
    
    random_numbers = PermutationRandom(16)
    assert len(random_numbers) == 16
    isValid = True
    for i in range(16):
        if i not in random_numbers:
            isValid = False
            break 
    assert isValid == True
    
    
    random_numbers = PermutationRandom(20)
    assert len(random_numbers) == 20
    isValid = True
    for i in range(20):
        if i not in random_numbers:
            isValid = False
            break 
    assert isValid == True
    
    random_numbers = PermutationRandom(50)
    assert len(random_numbers) == 50
    isValid = True
    for i in range(50):
        if i not in random_numbers:
            isValid = False
            break 
    assert isValid == True

    
    # Test Inversions
    
    tab = [3,5,6,7,10,14,11,9,4,13,2,0,8,1,12,15]
    assert 0 == Inversions(tab,1)
    assert 1 == Inversions(tab,2)
    assert 2 == Inversions(tab,3)
    assert 2 == Inversions(tab,4)
    assert 3 == Inversions(tab,5)
    assert 3 == Inversions(tab,6)
    assert 3 == Inversions(tab,7)
    assert 1 == Inversions(tab,8)
    assert 4 == Inversions(tab,9)
    assert 5 == Inversions(tab,10)
    assert 5 == Inversions(tab,11)
    assert 0 == Inversions(tab,12)
    assert 4 == Inversions(tab,13)
    assert 8 == Inversions(tab,14)
    assert 0 == Inversions(tab,15)
    
    # Test Soluble function
    
    assert Soluble([3, 5, 6, 7, 10, 14, 11, 9, 4, 13, 2, 0, 8, 1, 12, 15]) == True
    assert Soluble([0, 4, 7, 6, 3, 15, 12, 9, 10, 13, 1, 14, 2, 8, 5, 11]) == True
    assert Soluble([2, 15, 9, 0, 8, 11, 4, 12, 3, 10, 14, 5, 7, 1, 6, 13]) == True
    assert Soluble([10, 8, 4, 15, 9, 11, 7, 1, 13, 3, 6, 2, 12, 5, 0, 14]) == True
    assert Soluble([9, 10, 2, 3, 8, 11, 5, 15, 1, 14, 12, 0, 7, 4, 13, 6]) == False
    assert Soluble([10, 15, 2, 8, 1, 7, 5, 3, 9, 6, 12, 0, 4, 11, 14, 13]) == True
    assert Soluble([6, 13, 11, 12, 1, 5, 4, 2, 14, 15, 3, 7, 0, 9, 10, 8]) == False
    assert Soluble([13, 4, 5, 14, 15, 1, 11, 8, 7, 9, 3, 12, 6, 2, 0, 10]) == True
    assert Soluble([14, 4, 0, 13, 3, 15, 11, 5, 10, 1, 12, 8, 7, 6, 9, 2]) == True
    assert Soluble([13, 4, 5, 14, 15, 1, 11, 8, 7, 9, 3, 12, 6, 2, 0, 10]) == True
 
    
    # Test Initial function
    
    assert Soluble(Initial(16)) == True
    assert Soluble(Initial(4)) == True
    assert Soluble(Initial(9)) == True
    assert Soluble(Initial(16)) == True
    assert Soluble(Initial(4)) == True
    assert Soluble(Initial(9)) == True
    assert Soluble(Initial(16)) == True

# Testing. Uncomment following line to run tests
# testTaquin()

# Run 4 * 4 Grid
taquin(4)
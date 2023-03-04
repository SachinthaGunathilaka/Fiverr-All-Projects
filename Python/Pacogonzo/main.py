# The dictionary of collectables and their prices
oddCollection = {
    'Manual Typewriter': '$98.00',
    'Vinyl Record set': '$55.00',
    'Beanie Baby': '$50.00',
    'Rotary phone': '$50.00',
    'Vintage Monopoly board game': '$65.50',
    'Vintage Lunchbox': '$100.00',
    'Vintage Cabbage Patch Doll': '$45.00',
    'Antique Sewing Machine': '$250.00'
}


# Method to get option from the user
def getOption():
    # display menu
    displayMenu()

    # get user input for the menu option
    option = int(input("\nSelect the option : "))

    # Get user input until user enter valid input
    while option < 1 or option > 11:
        print("Invalid option")
        option = int(input("\nSelect the option again : "))

    return option


# Method to display the menu
def displayMenu():
    print("\n1).  Display all the Collectables and their Prices in the Collection")
    print("2).  Display how many Collectable exists in the Collection")
    print("3).  Display all the names of the Collectables in the Collection")
    print("4).  Display all the Collectables with Prices under $60.00 in the Collection")
    print("5).  Confirm that a Collectable is in the Collection")
    print("6).  Look up a specific Collectable's information")
    print("7).  Add a Collectable and its Price to the Collection")
    print("8).  Change a Collectable's price in the Collection")
    print("9).  Remove a Collectable and its Price from the Collection")
    print("10). Remove all Collectable and Price")
    print("11). Exit")


# Method to display dictionary items
def displayDictionaryItems():
    # Display labels
    print('\n{0:<30} {1:<20}'.format("Collectables", "Prices"))
    print("-" * 52)

    # Display item by item
    for key, value in oddCollection.items():
        print('{0:<30} {1:>20}'.format(key, value))


# Method to get number of items in the collection
def getNumberOfItems():
    print(f"\nNumber of Collectables in the inventory : {len(oddCollection)}")


# Method to display the names of the collection
def displayNames():
    print()
    # Iterate through each item and print the name
    for key in oddCollection.keys():
        print(key)


# Method to get items which are under 60$
def getAllUnder60():
    print()

    # Iterate through each item
    for key, value in oddCollection.items():
        # If the price of the item is less than 60, print it
        if float(value[1:]) < 60:
            print(key)


# Method to check whether the item is exists or not
def isExist(name):
    # Iterate through each item and compare the given name with the each key
    for key, value in oddCollection.items():
        if name == key.lower():
            return True

    return False


# Method to display details of an item
def searchForCollectable():
    # get user input for the name of the item
    name = str(input("\nEnter the name of the collectable : ")).lower()

    # Iterate through each item and display details of the relevant item
    for key, value in oddCollection.items():
        if name == key.lower():
            print(f"\n{name}  :  {oddCollection[key]}")
            return

    # If the item does not exist print error message
    print("\nCollectable not found")


# Method to add an item to collection
def addCollectable():
    # get user input for name, price and the confirmation
    name = str(input("\nEnter the name of the new collectable : ")).lower()
    price = input("Enter the price of the new collectable :$ ")
    price = '$' + price
    confirm = str(input("Are you sure to add ? (Yes-Y / No-N) :"))

    # If the user confirms
    if confirm.upper() == 'Y':
        # Check whether the item is already exists
        if isExist(name):
            print("\nCollectable already exists")
            return

        # Add new item to collection
        oddCollection[name] = price
        displayDictionaryItems()

    else:
        print("\nCanceled the operation")


# Method to change price of an item
def changePrice():
    # get user input for name, price and the confirmation
    name = str(input("\nEnter the name of the collectable : ")).lower()
    price = input("Enter the new price of the collectable :$ ")
    price = '$' + price
    confirm = str(input("Are you sure to update ? (Yes-Y / No-N) :"))

    # If the user confirms
    if confirm.upper() == 'Y':
        # Check whether the item is not exists
        if not isExist(name):
            print("\nCollectable does not exist")
            return

        # Iterate through the dictionary and update the price of the relavant item
        for key, value in oddCollection.items():
            if name == key.lower():
                oddCollection[key] = price
                displayDictionaryItems()
                return

    else:
        print("\nCanceled the operation")


# Method to remove an item from the collection
def removeCollectable():
    # get user input for name and the confirmation
    name = str(input("\nEnter the name of the collectable : ")).lower()
    confirm = str(input("Are you sure to delete ? (Yes-Y / No-N) :"))

    # If the user confirms
    if confirm.upper() == 'Y':
        # Check whether the item is not exists
        if not isExist(name):
            print("\nCollectable does not exist")
            return

        # Iterate through the dictionary and remove the relevant item
        for key, value in oddCollection.items():
            if name == key.lower():
                oddCollection.pop(key)
                displayDictionaryItems()
                return

    else:
        print("\nCanceled the operation")


# Method to remove all the elements from the collection
def removeAll():
    # get user input for the confirmation
    confirm = str(input("Are you sure to remove all ? (Yes-Y / No-N) :"))

    # If the user confirms
    if confirm.upper() == 'Y':
        # clear the dictionary
        oddCollection.clear()
        displayDictionaryItems()

    else:
        print("\nCanceled the operation !")


# Main program
option = 1

# While loop continuous until user wants to exit
while option != 11:
    # get user input
    option = getOption()

    # Execute relevant method according to the user input
    if option == 1:
        displayDictionaryItems()
    elif option == 2:
        getNumberOfItems()
    elif option == 3:
        displayNames()
    elif option == 4:
        getAllUnder60()
    elif option == 5:
        name = str(input("\nEnter the name of the collectable : ")).lower()
        if isExist(name):
            print("\nFound the collectable")
        else:
            print("\nCollectable not found")
    elif option == 6:
        searchForCollectable()
    elif option == 7:
        addCollectable()
    elif option == 8:
        changePrice()
    elif option == 9:
        removeCollectable()
    elif option == 10:
        removeAll()

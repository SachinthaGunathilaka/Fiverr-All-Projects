import random

# method to print the given word
def printWord(word):
    print("\nThe word is: ", end='')

    for letter in word:
        print(letter, end='')
    print()


# method to evaluate given letter
def EvaluateLetter(word, guessed_word, missed_chars, guessed_letter):
    # check whether the letter is already guessed
    if guessed_letter in missed_chars:
        return "already guessed", guessed_word

    i = 0

    # check whether the guessed letter is in the correct word
    if guessed_letter in word:
        is_right_guess = "correct guess"
    else:
        is_right_guess = "incorrect guess"

    # Reveal characters
    for c in word:
        if c == guessed_letter:
            guessed_word[i] = c
        i += 1
    return is_right_guess, guessed_word


# method to get user input for category
def getCategory():
    # Display menu and get user input
    game_type = int(input("\n1) Baby Animals\n"
                          "2) States\n"
                          "3) Words\n"
                          "Select Category : "))

    # If user input is invalid ask again
    while game_type < 1 or game_type > 3:
        print("Invalid Input")
        game_type = int(input("\n1) Baby Animals\n"
                              "2) States\n"
                              "3) Words\n"
                              "Select Category : "))

    return game_type


# Method to get level
def getLevel():
    # Display menu and get user input
    level = int(input("\n1) Normal\n"
                      "2) Hard\n"
                      "Select difficulty level : "))

    # If user input is invalid ask again
    while level not in [1, 2]:
        print("Invalid input")
        level = int(input("\n1) Normal\n"
                          "2) Hard\n"
                          "Select difficulty level : "))

    return level


# method to run game
def runGame(words, max_guesses):
    # Select word randomly
    word = words[random.randint(0, len(words) - 1)]
    # Display word using dashes
    guessed_word = list('_' * len(word))

    guess_index = 0
    missed_chars = []
    while True:
        # If the user lost all the lives
        if guess_index == max_guesses:
            print("You killed a man!")
            break

        # Print the word using dashes and ask letter from user
        printWord(guessed_word)
        guessed_letter = input("Guess a letter: ").upper()
        result, guessed_word = EvaluateLetter(word, guessed_word, missed_chars,
                                              guessed_letter)

        # If the letter is already guessed
        if result == "already guessed":
            print('You\'ve already entered this character.')
            continue

        # If the guessed letter is not the the word
        elif result == "incorrect guess":
            print(f"\nWrong guess. You have {max_guesses - guess_index - 1} lives.")
            missed_chars.append(guessed_letter)
            guess_index += 1

        # If the guessed letter is in the letter
        else:
            print("Correct guess !")
            printWord(guessed_word)

            # Ask whether user wants to guess the word
            option = input("Do you want to guess the word (y/n)? ").lower()

            # If the user wants to guess the word
            if option == "y":
                # Get user input for word
                guessing_word = input("Guess the word: ").upper()
                # If the word is correct
                if str(guessing_word) == word:
                    print("You just saved a man!")
                    break

                # If the word is not correct
                else:
                    print(f"\nWrong guess. You have {max_guesses - guess_index - 1} lives.")
                    guess_index += 1


# method to initialise the game
def initGame(category):
    words = []

    # Select filename according to the category
    filename = "words.txt"
    if category == 1:
        filename = "babyanimals.txt"
    elif category == 2:
        filename = "states.txt"

    # Read the file line by line
    f = open(filename, "r")
    lines = f.readlines()
    for line in lines:
        line = line.strip()
        if len(line) == 0:
            continue
        # Add word to the words list
        words.append(line.upper())

    f.close()

    return words


# main method
def main():
    # Initialise max_guesses to 5
    max_guesses = 5

    print('Welcome to Hangman')

    # get category from the user
    category = getCategory()
    # get difficulty level from the user
    level = getLevel()

    # Update max_guesses according to the difficulty level
    if level == 2:
        max_guesses = 3

    # run the game
    words = initGame(category)
    runGame(words, max_guesses)


# Execute the main method
main()

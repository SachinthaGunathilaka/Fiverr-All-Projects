# Import math module
import math

# Import numpy module
import numpy as np


# WordVectors class
class WordVectors:
    """ Provides basic word vector operations.
        Attributes:
            vectors: a dictionary containing words as keys and
                     corresponding vectors as values
    """

    # Constructor of the class (Takes filename as an argument)
    def __init__(self, filename):
        # Initialize empty dictionary(Attribute of the class)
        self.vectors = {}

        # Open file
        f = open(filename, "r")
        # Read all the lines from the file
        lines = f.readlines()

        # Iterate through each line
        for line in lines:
            # If the line is empty skip that line
            if len(line.strip()) == 0:
                continue

            # Split the line by spaces
            row_data = line.split()
            # Add word and the vector to the vectors dictionary
            self.vectors[row_data[0]] = np.array(row_data[1:], dtype=float)

    # similarity method (Takes w1 and w2 as arguments)
    def similarity(self, w1, w2):
        # Get the vector of the first word
        vector1 = self.vectors[w1]
        # Get the vector of the second word
        vector2 = self.vectors[w2]

        # Calculate similarity using numpy functions
        return np.dot(vector1, vector2) / (np.linalg.norm(vector1) * np.linalg.norm(vector2))

    # related_words function (Get w as an argument)
    def related_words(self, w):

        # Initialize the least similarity word to empty string
        least_sim_word = ""
        least_sim_value = math.inf

        # Initialize the least similarity word to empty string
        most_sim_word = ""
        most_sim_value = 0

        # Iterate through each word in the vectors dictionary
        for word in self.vectors.keys():

            # If the current word is same as the word w, skip it
            if word == w:
                continue

            # Calculate similarity between current word and w
            similarity_val = self.similarity(w, word)

            # If the similarity of current word is less than least_sim_value
            if similarity_val < least_sim_value:
                # Update least_sim_value
                least_sim_value = similarity_val
                # Set least_sim_word as the current word
                least_sim_word = word

            # If the similarity of current word is greater than least_sim_value
            if similarity_val > most_sim_value:
                # Update most_sim_value
                most_sim_value = similarity_val
                # Set most_sim_word as the current word
                most_sim_word = word

        # Return least_sim_word and most_sim_word as a tuple
        return least_sim_word, most_sim_word


if __name__ == "__main__":
    wordvec = WordVectors("wordvectors20.txt")
    print(len(wordvec.vectors))  # 20
    print(len(wordvec.vectors["happy"]))  # 15

    print(wordvec.similarity("happy", "cheerful"))  # 0.756762538907714
    print(wordvec.similarity("happy", "sad"))  # 0.23285641687730718

    print(wordvec.related_words("party"))  # ('suffering', 'celebration')
    print(wordvec.related_words("enemy"))  # ('happy', 'adversary')
    print(wordvec.related_words("love"))  # ('cheerful', 'romantic')

if __name__ == '__main__':

    import json

    # Opening JSON file
    f = open('Output/0.json')

    # returns JSON object as
    # a dictionary
    data = json.load(f)

    # Iterating through the json
    # list
    print(data["dna"])

    # Closing file
    f.close()
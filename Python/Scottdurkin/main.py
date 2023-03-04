import random


# Function for register participants
def registerParticipants(teams):
    # Initialize participants list to empty
    participants = []

    # Iterate thorough each team
    for team in teams:
        # Add 5 members from each team to participants list
        for i in range(1, 6):
            participants.append(team + "-member" + str(i))

    # Return participants list
    return participants


# Function to compete participants
def compete(participants, events):
    # Initialize winners to empty list
    winners = []
    # Initialize positions list
    positions = ["1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th", "10th"]

    # Iterate through each event
    for event in events:
        # Shuffle participants list
        random.shuffle(participants)
        # Get first 10 participants as the winners
        temp = participants[:10]
        # Add winners list to temp list
        winners.append(temp)

        # Display winners
        print(f"\nWinners of {event} event")
        print("--------------------------")

        # Iterate through each winner and display
        for i in range(1, len(temp) + 1):
            print(f"{positions[i - 1]} place : {temp[i - 1]}")

    # return winners list
    return winners


# Function to calculate scores
def calculateScores(winners):
    # Initialize scores list
    scores = {"red": 0, "blue": 0, "green": 0, "black": 0, "white": 0}
    # Iterate though each event
    for event in winners:
        # Iterate through winners of each event
        for i in range(len(event)):
            # Calculate total score
            team, member = event[i].split("-")
            scores[team] += 10 - i

    # Return scores list
    return scores


# Function to display results
def displayResults(scores):
    print("\nTotal points")
    print("----------------")

    winning_team = ""

    # Iterate through each event scores
    winning_score = 0
    for key in scores.keys():
        # Calculate winning team
        if winning_score < scores[key]:
            winning_team = key
            winning_score = scores[key]

        # Display each team score
        print(f"Team {key} : {scores[key]}")

    # display winning team
    print(f"\nWinning team : Team {winning_team} ({winning_score} Points)")


# Main function
if __name__ == '__main__':
    # Initialize teams list
    teams = ["red", "blue", "green", "black", "white"]
    # Initialize events list
    events = ["100m", "200m", "400m", "800m", "1200m"]

    # Call registerParticipants
    participants = registerParticipants(teams)
    # Call compete
    winners = compete(participants, events)
    # Call calculateScores
    scores = calculateScores(winners)
    # Call displayResults
    displayResults(scores)

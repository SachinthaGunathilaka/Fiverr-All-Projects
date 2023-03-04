import math
import random

# Indices of the cities
indices_cities = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]
size = 100 # number of generated paths
routes_length = [0] * size
# To hold the length of each path
routes_fitness = [0] * size
# Initialize cost of the best path as infinity
best_path_cost = math.inf


def displayPath(path, cost, title):
    print(title, end="")
    cities_names = ["Atlanta", "Boston", "Chicago", "Dallas", "Denver", "Houston", "Las Vegas", "Los Angeles", "Miami",
                    "New Orleans", "New York", "Phoenix", "San Francisco", "Seattle", "Washington D.C."]

    # print(path)
    for i in range(len(path)):
        if i != len(path) - 1:
            print(cities_names[path[i]], end=", ")
        else:
            print(cities_names[path[i]])

    print("\tPath cost is : ", cost)


# distances matrix
distance_matrix = [[0, 1095, 715, 805, 1437, 844, 1920, 2230, 675, 499, 884, 1832, 2537, 2730, 657],
                   [1095, 0, 983, 1815, 1991, 1886, 2500, 3036, 1539, 1541, 213, 2664, 3179, 3043, 44],
                   [715, 983, 0, 931, 1050, 1092, 1500, 2112, 1390, 947, 840, 1729, 2212, 2052, 695],
                   [805, 1815, 931, 0, 801, 242, 1150, 1425, 1332, 504, 1604, 1027, 1765, 2122, 1372],
                   [1437, 1991, 1050, 801, 0, 1032, 885, 1174, 2094, 1305, 1780, 836, 1266, 1373, 1635],
                   [844, 1886, 1092, 242, 1032, 0, 1525, 1556, 1237, 365, 1675, 1158, 1958, 2348, 1443],
                   [1920, 2500, 1500, 1150, 885, 1525, 0, 289, 2640, 1805, 2486, 294, 573, 1188, 2568],
                   [2230, 3036, 2112, 1425, 1174, 1556, 289, 0, 2757, 1921, 2825, 398, 403, 1150, 2680],
                   [675, 1539, 1390, 1332, 2094, 1237, 2640, 2757, 0, 892, 1328, 2359, 3097, 3389, 1101],
                   [499, 1541, 947, 504, 1305, 365, 1805, 1921, 892, 0, 1330, 1523, 2269, 2626, 1098],
                   [884, 213, 840, 1604, 1780, 1675, 2486, 2825, 1328, 1330, 0, 2442, 3036, 2900, 229],
                   [1832, 2664, 1729, 1027, 836, 1158, 294, 398, 2359, 1523, 2442, 0, 800, 1482, 2278],
                   [2537, 3179, 2212, 1765, 1266, 1958, 573, 403, 3097, 2269, 3036, 800, 0, 817, 2864],
                   [2730, 3043, 2052, 2122, 1373, 2348, 1188, 1150, 3389, 2626, 2900, 1482, 817, 0, 2755],
                   [657, 440, 695, 1372, 1635, 1443, 2568, 2680, 1101, 1098, 229, 2278, 2864, 2755, 0]]


# get distance between 2 cities
def getDistance(city1, city2):
    return distance_matrix[city1][city2]


# calculate lengths of the given paths
def calculateRouteLength(generated_paths):
    # Iterate through each path
    for path_index in range(len(generated_paths)):
        path_length = 0
        # iterate through each city in each path
        for city_index in range(1, len(indices_cities)):
            # update path_length
            path_length += getDistance(generated_paths[path_index][city_index - 1],
                                       generated_paths[path_index][city_index])

        # Add path_length to routes_length list
        routes_length[path_index] = path_length
        # calculate fitness value
        routes_fitness[path_index] = 1 / routes_length[path_index]

# function that picks a parent Fitness Proportionate Selection
def selectRouletteWheel():
    # sum of fineness and partial sum
    sum_of_fineness = 0
    partial_sum = 0

    # choosing an individual
    individual = 0

    # get the sum of fitness
    for fitness in routes_fitness:
        sum_of_fineness += fitness

    # choose random number between 0 and sum of fitness
    random_num = random.uniform(0, sum_of_fineness)
    for fitness in routes_fitness:
        # adding the finesses to the partial sum until partial sum is smaller than random sum
        if partial_sum < random_num:
            partial_sum = partial_sum + fitness
            individual += 1

    # if the selected individual is equal to size return size - 1
    if individual == size:
        return size - 1
    return individual


# get the fittest path
def getBestPath():
    minimum_cost = math.inf
    fittest_path_index = 0

    # iterate through each value in routes_length
    for i in range(size):
        # get the minimum value by comparing
        if routes_length[i] < minimum_cost:
            minimum_cost = routes_length[i]
            fittest_path_index = i

    # return index of the fittest path
    return fittest_path_index


# PMX crossover
def partiallyMatchedCrossover(ind1, ind2):
    parent1 = [0] * len(indices_cities)
    parent2 = [0] * len(indices_cities)

    # Initialize the position of each indices in the individuals
    for k in range(len(indices_cities)):
        parent1[ind1[k]] = k
        parent2[ind2[k]] = k

    # Choose crossover points
    cxpoint1 = random.randint(0, len(indices_cities))
    cxpoint2 = random.randint(0, len(indices_cities) - 1)

    if cxpoint2 < cxpoint1:
        cxpoint1, cxpoint2 = cxpoint2, cxpoint1 # swapping
    else:
        cxpoint2 += 1

    # Apply crossover between cx points
    for k in range(cxpoint1, cxpoint2):
        # Keep track of the selected values
        temp1 = ind1[k]
        temp2 = ind2[k]
        # Swap the matched value
        ind1[k], ind1[parent1[temp2]] = temp2, temp1
        ind2[k], ind2[parent2[temp1]] = temp1, temp2
        # Position bookkeeping
        parent1[temp1], parent1[temp2] = parent1[temp2], parent1[temp1]
        parent2[temp1], parent2[temp2] = parent2[temp2], parent2[temp1]

    return ind1, ind2


# main function
if __name__ == '__main__':
    generated_paths = []
    num_of_generations = 100

    # generate paths
    for _ in range(size):
        generated_paths.append(random.sample(indices_cities, len(indices_cities)))
    calculateRouteLength(generated_paths) # call calculateRouteLength function

    # Display length of the initial paths
    print("Initial paths  =>", )
    # for index in range(len(generated_paths)):
    #     displayPath(generated_paths[index], routes_length[index], "\nPath " + str(index + 1) + " :  ")
    print("\tPath lengths : ", routes_length)

    best_path = []

    # Iterate for each generation
    for j in range(num_of_generations):
        for i in range(0, size, 2):
            # select parents for using Roulette Wheel Selection
            parent1 = selectRouletteWheel()
            parent2 = selectRouletteWheel()

            # Iterate until 2 different parent obtain
            while True:
                if parent1 == parent2:
                    parent2 = selectRouletteWheel()
                else:
                    break

            ind1 = generated_paths[parent1].copy()
            ind2 = generated_paths[parent2].copy()

            parent1 = [0] * len(indices_cities)
            parent2 = [0] * len(indices_cities)

            # Initialize the position of each indices in the individuals
            for k in range(len(indices_cities)):
                parent1[ind1[k]] = k
                parent2[ind2[k]] = k

            # Choose crossover points
            cxpoint1 = random.randint(0, len(indices_cities))
            cxpoint2 = random.randint(0, len(indices_cities) - 1)

            if cxpoint2 < cxpoint1:
                cxpoint1, cxpoint2 = cxpoint2, cxpoint1  # swapping
            else:
                cxpoint2 += 1

            # Apply crossover between cx points
            for k in range(cxpoint1, cxpoint2):
                # Keep track of the selected values
                temp1 = ind1[k]
                temp2 = ind2[k]
                # Swap the matched value
                ind1[k], ind1[parent1[temp2]] = temp2, temp1
                ind2[k], ind2[parent2[temp1]] = temp1, temp2
                # Position bookkeeping
                parent1[temp1], parent1[temp2] = parent1[temp2], parent1[temp1]
                parent2[temp1], parent2[temp2] = parent2[temp2], parent2[temp1]

            # update the generated_paths
            generated_paths[i], generated_paths[i + 1] = ind1, ind2
            # calculate lengths for updated generation
            calculateRouteLength(generated_paths)

        # pick the paths for mutation based on a probability
        for i in range(size):
            rand = random.uniform(0, 1)
            # if the generated number less than 0.1
            if rand < 0.1:
                # swap with a probability 2 indices_cities in a route
                picks = random.sample(range(len(indices_cities)), 2)
                temp = generated_paths[i][picks[0]]
                generated_paths[i][picks[0]] = generated_paths[i][picks[1]]
                generated_paths[i][picks[1]] = temp

        # calculate lengths after mutation
        calculateRouteLength(generated_paths)

        # find best path overall
        if routes_length[getBestPath()] < best_path_cost:
            index = getBestPath()
            best_path_cost = routes_length[index]
            best_path = generated_paths[index].copy() # assign best path so far

        # display best path for the generation
        print("\n\nGeneration ", j+1, "=>")
        print("\tPath lengths : ", routes_length)
        displayPath(generated_paths[getBestPath()], routes_length[getBestPath()], "\n\tBest path of generation " + str(j+1) + " : ")

    # display best path at the end
    print("\n\nFinally => ")
    displayPath(best_path, best_path_cost, "\tBest path is :  ")

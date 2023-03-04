N = int(input())
locations = []
for i in range(N):
    dir, position = input().strip().split()

    if dir == 'G':
        dir = -1

    else:
        dir = 1

    locations.append([position, dir])

minLiars = N
locations.sort(key=lambda x: x[0])

for idx in range(N):
    numLiars = 0

    for jdx in range(idx):

        if locations[jdx][1] == 1:
            numLiars += 1

    for jdx in range(idx+1, N):
        if locations[jdx][1] == -1:
            numLiars += 1

    minLiars = min(numLiars, minLiars)

print(minLiars)

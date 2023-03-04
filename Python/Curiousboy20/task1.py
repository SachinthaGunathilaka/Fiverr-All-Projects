from os import listdir
from os.path import isfile, join
import matplotlib.pyplot as plt

path = "data"
files = [f for f in listdir(path) if isfile(join(path, f))]

pedestrian_counts = {}
heights = []
widths = []
lengths = []


for i in range(8):
    pedestrian_counts[i] = 0

for file in files:
    f = open(path + "/" + file)
    lines = f.readlines()

    word_count = 0
    for line in lines:
        words = line.split()
        word_count += words.count("pedestrian")

        if word_count in pedestrian_counts:
            pedestrian_counts[word_count] += 1
        else:
            pedestrian_counts[word_count] = 1

        heights.append(words[8])
        widths.append(words[9])
        lengths.append(words[10])

    f.close()



plt.bar(list(pedestrian_counts.keys()), pedestrian_counts.values(), color='g')
plt.title('Pedestrian Word Count')
plt.xlabel("Pedestrian Count")
plt.ylabel("Number of Files")
plt.show()

print(heights)
_, bins, _ = plt.hist(heights, 10)
plt.title('Heights Count')
plt.xlabel('Height')
plt.ylabel('Count')
plt.xticks(bins)
plt.show()


_, bins, _ = plt.hist(widths, 10)
plt.title('Widths Count')
plt.xlabel('Width')
plt.ylabel('Count')
plt.xticks(bins)

plt.show()

_, bins, _ = plt.hist(lengths, 10)
plt.title('Lengths Count')
plt.xlabel('Length')
plt.ylabel('Count')
plt.xticks(bins)
plt.show()




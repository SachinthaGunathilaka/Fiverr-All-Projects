
import csv

filename = input()

words = []
with open(filename, 'r') as file:
    reader = csv.reader(file)

    for row in reader:
        words.extend(row)

unique_words = []

for word in words:
    if word not in unique_words:
        unique_words.append(word)


for unique_word in unique_words:
    print(f"{unique_word} {words.count(unique_word)}")

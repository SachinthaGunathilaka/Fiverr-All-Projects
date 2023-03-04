import numpy as np
import pandas as pd

df = pd.read_excel("input.xlsx")


def toInt(str_val):
    return int(str_val)


all_data = list(df.iloc[:, 2])
excluded_sequences = []
for data in all_data:
    try:
        row = list(map(int, data.split()))
        row.sort()
        excluded_sequences.append(row)
    except:
        continue

excluded_sequences = np.array(excluded_sequences)

random_numbers = []

while True:
    new_numbers = np.sort(np.random.randint(1, 61, 5))
    if not np.any(np.all(np.isin(excluded_sequences, new_numbers, True), axis=1)):
        random_numbers = new_numbers
        break

print(random_numbers)

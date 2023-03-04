import pandas as pd
import unidecode
from datetime import datetime


def getOverlapTime(id1, id2):
    sDate1 = datetime.strptime(df.iloc[id1][2], "%Y-%m-%dT%H:%M:%S.%f%z")
    eDate1 = datetime.strptime(df.iloc[id1][3], "%Y-%m-%dT%H:%M:%S.%f%z")
    sDate2 = datetime.strptime(df.iloc[id2][2], "%Y-%m-%dT%H:%M:%S.%f%z")
    eDate2 = datetime.strptime(df.iloc[id2][3], "%Y-%m-%dT%H:%M:%S.%f%z")

    if (sDate1 < sDate2 and eDate1 < sDate2) or (sDate1 > sDate2 and eDate2 < sDate1):
        return 0

    return (min(eDate1, eDate2) - max(sDate1, sDate2)).seconds / 60


def getSmallestDuration(id1, id2):
    sDate1 = datetime.strptime(df.iloc[id1][2], "%Y-%m-%dT%H:%M:%S.%f%z")
    eDate1 = datetime.strptime(df.iloc[id1][3], "%Y-%m-%dT%H:%M:%S.%f%z")
    sDate2 = datetime.strptime(df.iloc[id2][2], "%Y-%m-%dT%H:%M:%S.%f%z")
    eDate2 = datetime.strptime(df.iloc[id2][3], "%Y-%m-%dT%H:%M:%S.%f%z")

    if eDate1 - sDate1 < eDate2 - sDate2:
        return [id1, id2]

    return [id2, id1]


def getUnitOverlap(id1, id2):
    units1 = unidecode.unidecode(df.iloc[id1].unit_ids.strip()[1:-1]).replace(" ", "").split(",")
    units2 = unidecode.unidecode(df.iloc[id2].unit_ids.strip()[1:-1]).replace(" ", "").split(",")
    return len([value for value in units1 if value in units2]) / len(units1)


def isDuplicate(id1, id2):
    if getOverlapTime(id1, id2) >= 10 and getUnitOverlap(id1, id2) >= 0.7:
        units1 = unidecode.unidecode(df.iloc[id1].unit_ids.strip()[1:-1]).replace(" ", "").split(",")
        units2 = unidecode.unidecode(df.iloc[id2].unit_ids.strip()[1:-1]).replace(" ", "").split(",")

        if len(units1) < len(units2):
            return [id1, id2]
        elif len(units1) > len(units2):
            return [id2, id1]

        else:
            return getSmallestDuration(id1, id2)

    return None


if __name__ == '__main__':
    input_file = "Sample dataset raw.csv"
    output_file = "output.csv"

    # Input file name
    df = pd.read_csv(input_file)



    duplicates = []
    duplicates_original = []
    for i in range(len(df)):
        for j in range(i + 1, len(df)):
            flag = isDuplicate(i, j)
            if flag is None:
                continue

            if flag not in duplicates:
                duplicates.append(flag[0])
                duplicates_original.append(flag[1])

    is_duplicates_col = []
    duplicates_col = []
    num_of_units_col = []
    for i in range(len(df)):
        if i in duplicates:
            is_duplicates_col.append(1)

            index = duplicates.index(i)
            duplicates_col.append(duplicates_original[index])

        else:
            is_duplicates_col.append(0)
            duplicates_col.append("")

        units = unidecode.unidecode(df.iloc[i].unit_ids.strip()[1:-1]).replace(" ", "").split(",")
        num_of_units_col.append(len(units))

    reference_col = [i for i in range(len(df))]
    df.insert(loc=0, column='', value=reference_col)
    df.insert(loc=1, column='IsDuplicate', value=is_duplicates_col)
    df.insert(loc=2, column='RelatedDuplicate', value=duplicates_col)
    df.insert(loc=3, column='NumberOfUnits', value=num_of_units_col)

    df.to_csv(output_file, sep=',', encoding='utf-8', index=False)

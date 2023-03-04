def reverseListOfList(input_list):
    if len(input_list) == 0:
        return []
    if len(input_list[0]) == 0:
        input_list.pop(0)

        result = reverseListOfList(input_list)

        result.append([])
        return result

    first_element = input_list[0][0]
    input_list[0].pop(0)

    result = reverseListOfList(input_list)
    result[-1].append(first_element)

    return result


input_li = [[0], [1, 2, 3], [4, 5], [6, 7, 8, 9]]
ex = [1, 2, 3, 4, 5]
print(reverseListOfList(input_li))

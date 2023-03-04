# input_data = ["abc", "def"]
#
#
# def reverseList(input_list):
#     if len(input_list) == 0:
#         return input_list
#
#     return [input_list[-1][::-1]] + reverseList(input_list[:-1])
#
#
# print(reverseList(input_data))


def sortList(input_list):
    for i in range(len(input_list) - 1):
        for j in range(0, len(input_list) - i - 1):
            if input_list[j] < input_list[j + 1]:
                input_list[j], input_list[j + 1] = input_list[j + 1], input_list[j]

    return input_list


input_data = [10, 3, 7, 5, 2, 11, 16]
print(sortList(input_data))

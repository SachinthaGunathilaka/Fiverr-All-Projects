def numberOfVowels(text):
    count = 0
    for letter in text.lower():
        if letter in ['a', 'e', 'i', 'o', 'u']:
            count += 1

    return count


def numOfFactors(number):
    count = 0
    for divider in range(1, number + 1):
        if number % divider == 0:
            count += 1

    return count


# num = 2
# print(numOfFactors(num))

# print({'name': 'fatima', 'occupation': 'military', 'city': 'houston'}['city'])
# print(['one', 'two', 'three'][2][0:2])
# print(type('this is mac108'.split()))


def words_by_letter_count(text):
    dictionary_by_word_length = {}
    for word in text.split():
        if len(word) in dictionary_by_word_length:
            dictionary_by_word_length[len(word)].append(word)
        else:
            dictionary_by_word_length[len(word)] = [word]
    return dictionary_by_word_length


# print(words_by_letter_count('hey all how are you doing today'))

# i = 0
# for x in range(1, 3):
#     i += 1
#     j = 0
#     for y in range(x, 5):
#         j += 1
#         print(f"\nOuter Loop iteration {i} ")
#         print(f"\tInner Loop iteration {j}")
#         print(f"x = {x}  y = {y}  printed_value = {x*y}")
#         # print(x * y)


def letter_frequency(s):
    letter_frequency_dict = {}
    i = 0
    for letter in s:
        i += 1
        print(f"\nIteration {i}")
        print(f"\tstart: letter = {letter} letter_frequency_dict={letter_frequency_dict}")
        # start
        if letter in letter_frequency_dict:
            letter_frequency_dict[letter] += 1
        else:
            letter_frequency_dict[letter] = 1
        # end
        print(f"\tend: letter = {letter} letter_frequency_dict={letter_frequency_dict}")

    return letter_frequency_dict


print(letter_frequency('good'))
# {'d': 1, 'g': 1, 'o': 2}


# itteration 1
#     start: letter = g letter_frequency_dict = {}
#     end: letter = g letter_frequency_dict = {'g': 1}

# itteration 2
#     start: letter = o letter_frequency_dict = {'g': 1}
#     end: letter = o letter_frequency_dict = {'g': 1, 'o': 1}

# itteration 3
#     start: letter = o letter_frequency_dict = {'g': 1, 'o': 1}
#     end: letter = o letter_frequency_dict = {'g': 1, 'o': 2}

# itteration 4
#     start: letter = d letter_frequency_dict = {'g': 1, 'o': 2}
#     end: letter = d letter_frequency_dict = {'g': 1, 'o': 2, 'd': 1}
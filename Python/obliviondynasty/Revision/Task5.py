def validateName(username):
    username = username.strip()

    splitted_names = username.split()
    correct_name = ""

    for i in range(len(splitted_names)):

        if i != len(splitted_names)-1:
            correct_name += splitted_names[i].capitalize() + " "

        else:
            correct_name += splitted_names[i].capitalize()

    return correct_name


username = input()
print(validateName(username))

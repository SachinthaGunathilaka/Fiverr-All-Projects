names_list = ["Ryley", "Edan", "Reagan", "Henry", "Caius", "Jane", "Guto", "Sonya",  "Tyrese", "Johnny"]

input_value = int(input("Enter index: "))

try:
    print(f"Name: {names_list[input_value]}")

except IndexError:
    print("Exception! list index out of range")

    if input_value < 0:
        print(f"The closest name is: {names_list[0]}")

    else:
        print(f"The closest name is: {names_list[-1]}")

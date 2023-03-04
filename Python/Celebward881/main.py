styles = ["sapphire", "diamond", "ruby", "onyx", "amethyst"]
style_prices = [55.95, 100, 69.95, 79.95, 2.99]

extras = ["Marquise", "Round", "Oval", "Square", "Oblong"]
extra_prices = [7.99, 9.99, 3.99, 2.99, 3.42]

selections = {}


def primaryMenu():
    print("\n1) sapphire ($55.95)\n"
          "2) diamond ($100)\n"
          "3) ruby ($69.95)\n"
          "4) onyx ($79.95)\n"
          "5. amethyst ($2.99)")


def secondaryMenu():
    print("\n1) Marquise ($7.99)\n"
          "2) Round ($9.99)\n"
          "3) Oval (3.99)\n"
          "4) Square ($2.99)\n"
          "5) Oblong ($3.42)\n"
          "6) Done")


primaryMenu()
selections["style"] = int(input("\nSelect style: "))
while selections["style"] < 1 or selections["style"] > 5:
    print("Invalid style")
    selections["style"] = int(input("\nSelect style: "))

available_options = [2, 3]
if selections["style"] == 1 or selections["style"] == 4:
    available_options.append(4)
elif selections["style"] == 2 or selections["style"] == 3:
    available_options.append(1)
else:
    available_options.append(5)

selections["extras"] = []
while True:

    secondaryMenu()
    extra = int(input("\nSelect extra option: "))
    while extra != 6 and extra not in available_options:
        print("Option not available")
        extra = int(input("Enter another option: "))

    if extra == 6:
        break

    if extra in selections["extras"]:
        print("Selected extra has been already selected.")

    else:
        selected_extras = selections["extras"]
        selected_extras.append(extra)
        selections["extras"] = selected_extras

total_bill = style_prices[selections["style"] - 1]

for extra in selections["extras"]:
    total_bill += extra_prices[extra - 1]

print("\nStyle: " + styles[selections["style"] - 1])
print("\nExtra Options : ")

for extra in selections["extras"]:
    print("\t" + str(extras[extra - 1]))

print("\nTotal Bill: $" + str(round(total_bill, 2)))

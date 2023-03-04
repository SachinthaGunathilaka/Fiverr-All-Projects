product_price = 100

print("\n-------------------------------")
print("        SOFTWARE SALES")
print("-------------------------------\n")

name = input("Enter your name : ")
quantity = int(input("Enter number of packages : "))

sub_total = product_price * quantity
discount_percentage = 0

if quantity >= 100:
    discount_percentage = 0.4

elif quantity >= 50:
    discount_percentage = 0.3

elif quantity >= 20:
    discount_percentage = 0.2

elif quantity >= 10:
    discount_percentage = 0.1

discount_amount = sub_total * discount_percentage
total_price = sub_total - discount_amount


print(f"\nName: {name}")
print(f"Quantity of Packages: {quantity}")
print("Discount Percentage: {:.2f}%".format(discount_percentage))
print("Sub Total: ${:.2f}".format(sub_total))
print("Discount Amount: ${:.2f}".format(discount_amount))
print("Total Price: ${:.2f}".format(total_price))


print("\n-------------------------------")
print("         THANK YOU")
print("-------------------------------")

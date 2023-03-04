# Import libraries
from tkinter import *
from tkinter import messagebox


# CreepyCrab class
class CreepyCrab:
    # constructor
    def __init__(self):
        # burgers with prices
        self.burger_prices = [["Beef Burger", 4], ["Veggie Burger", 5], ["Salad", 6]]
        self.root = Tk()

        # set title of the window
        self.root.title('The Creepy Crab')
        # set window size
        self.root.geometry("300x350")

        # Display title
        title = Label(self.root, text="The Creepy Crab", pady=10).pack()
        # Display message
        message = Label(self.root, text="Please make your selection(s).", pady=5).pack()

        # burger types with an index (For radio button)
        burger_types = [
            ("Beef Burger - $4", 0),
            ("Veggie Burger - $5", 1),
            ("Salad - $6", 2)]

        # Define Tkinter integer variable hold the selected burger from the radio buttons
        self.selected_burger = IntVar()
        # Initialize selected burger to -1
        self.selected_burger.set(-1)

        # Iterate through each burger type
        for name, value in burger_types:
            # Add radio button for each burger type
            Radiobutton(self.root, text=name, variable=self.selected_burger, value=value).pack(anchor=W, padx=(100, 0),
                                                                                               pady=2)

        # Define tkinter integer variables for checkboxes
        self.fries_selected = IntVar()
        self.drink_selected = IntVar()
        self.cookie_selected = IntVar()

        # check button for fries
        fries_checkbutton = Checkbutton(self.root, text="Fries - $3", variable=self.fries_selected).pack(anchor=W,
                                                                                                         padx=(100, 0),
                                                                                                         pady=(20, 2))

        # check button for drink
        drink_checkbutton = Checkbutton(self.root, text="Drink - $3", variable=self.drink_selected).pack(anchor=W,
                                                                                                         padx=(100, 0),
                                                                                                         pady=2)

        # check button for cookie
        cookie_checkbutton = Checkbutton(self.root, text="Cookie - $2", variable=self.cookie_selected).pack(anchor=W,
                                                                                                            padx=(
                                                                                                                100, 0),
                                                                                                            pady=2)

        # order button (When this button clicked, placeOrder method will be executed)
        order_button = Button(self.root, text="Place Order", command=self.placeOrder).pack(side="left", anchor="n",
                                                                                           padx=(95, 0), pady=10)

        # quit button (When this button clicked, window will be closed)
        quit_button = Button(self.root, text="Quit", command=self.root.destroy).pack(side="left", anchor="n", pady=10)

        self.root.mainloop()

    # placeOrder method
    def placeOrder(self):
        count = self.fries_selected.get() + self.drink_selected.get() + self.cookie_selected.get()

        # calculate price for toppings
        total = self.fries_selected.get() * 3 + self.drink_selected.get() * 3 + self.cookie_selected.get() * 2

        text = ""
        is_burger = self.selected_burger.get() != -1

        # If a burger is selected
        if is_burger:
            # calculate total price and generate text
            total += self.burger_prices[self.selected_burger.get()][1]
            text = self.burger_prices[self.selected_burger.get()][0]

            # If all the toppings are selected
            if count == 3:
                text += " with Fries, a Drink and a Cookie."

            # If only 2 toppings are selected
            elif count == 2:
                # If fries and drink are selected
                if self.fries_selected.get() == 1 and self.drink_selected.get() == 1:
                    text += " with Fries and a Drink."

                # If fries and cookie are selected
                elif self.fries_selected.get() == 1 and self.cookie_selected.get() == 1:
                    text += " with Fries and a Cookie."

                # If drink and cookie are selected
                else:
                    text += " with a Drink and a Cookie."

            # If only 1 topping is selected
            elif count == 1:
                # If fries is selected
                if self.fries_selected.get() == 1:
                    text += " with Fries."

                # If drink is selected
                elif self.drink_selected.get() == 1:
                    text += " with a Drink."

                # If cookie is selected
                else:
                    text += " with a Cookie."

        # If no burger is selected
        else:
            # If all the toppings are selected
            if count == 3:
                text += "Fries, a Drink and a Cookie."

            # If only 2 toppings are selected
            elif count == 2:
                if self.fries_selected.get() == 1 and self.drink_selected.get() == 1:
                    text += "Fries and a Drink."
                elif self.fries_selected.get() == 1 and self.cookie_selected.get() == 1:
                    text += "Fries and a Cookie."
                else:
                    text += "A Drink and a Cookie."

            # If only 1 topping is selected
            elif count == 1:
                if self.fries_selected.get() == 1:
                    text += "An order of Fries."
                elif self.drink_selected.get() == 1:
                    text += "One Drink."
                else:
                    text += "One Cookie."

        text += "\nYou owe $" + str(total) + "."

        # display a message box with order details
        response = messagebox.showinfo("Order Summary", text)


# Main method
if __name__ == '__main__':
    # Create object of CreepyCrab
    creepy_crab = CreepyCrab()

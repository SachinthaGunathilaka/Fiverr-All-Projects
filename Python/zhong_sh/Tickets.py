from Passengers import *

# *****  Tickets class - is a 'child class' of Passengers Class


class Tickets(Passengers):
    def __init__(self, trip_type, origin, destination, departure_date, cabin_class, no_of_passengers):
        super().__init__(trip_type, origin, destination, departure_date, cabin_class, no_of_passengers)

    def set_seat_options(self, selection, seats):
        self.selection = selection
        self.seats = seats

    def check_avaiability(self, cabin_configuration):

        seat_configs = []
        for cabin in cabin_configuration:
            seat_rows = cabin[1].split("-")
            last_seat = 0
            for seat_row in seat_rows:
                last_seat += int(seat_row)

            seat_configs.append([int(cabin[2]), 'A', int(cabin[3]), chr(ord('A') + last_seat - 1)])

        # print(seat_configs)

        for seat in self.seats:

            letter = seat[-1]
            number = int(seat[:-1])
            is_find = False
            for seat_config in seat_configs:

                if seat_config[1] <= letter <= seat_config[3] and seat_config[0] <= number <= seat_config[2]:
                    is_find = True
                    break

            if not is_find:
                print("Selected seats are not available.Your flight is canceled.")
                return

        print("Your flight is confirmed.")


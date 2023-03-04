# PyFlight

# Initial data is loaded in the files created for Classes
# importing classes saved in other files

from createAircraftType import *
from createAirline import *
from createFlight import *
from Passengers import *
from Tickets import *

from datetime import datetime

# Creating objects needed in following functions

airlines_obj = Airlines()
aircrafts_obj = Aircrafts()
flights_obj = Flights()


def create_airline():
    airline_name = input("Airline name - ")
    iata_code = input("IATA code - ")
    airline1 = Airline(iata_code, airline_name)

    if airlines_obj.is_exist(airline1):
        print("This record already exist")
    else:
        airlines_obj.create_record(airline1)
        print("Airline is created successfully")


def create_aircraft_type():
    iata_code = input("Airline IATA code - ")
    type_name = input("Aircraft Type Name - ")

    print("Cabin class configuration")
    add_cabin = input("Add cabin class(Y/N) - ")
    cabin_configurations = []

    while add_cabin == "Y":
        cabin_configuration = []

        cabin_class = input("Cabin Class - ")
        cabin_configuration.append(cabin_class)

        seat_configuration = input("Seat Configuration - ")
        cabin_configuration.append(seat_configuration)

        start_row_no = input("Starting Row Number - ")
        cabin_configuration.append(start_row_no)

        end_row_no = input("Ending Row Number - ")
        cabin_configuration.append(end_row_no)

        cabin_configurations.append(cabin_configuration)
        add_cabin = input("Add cabin class(Y/N) - ")

    aircraft1 = Aircraft(iata_code, type_name, cabin_configurations)
    if aircrafts_obj.is_exist(aircraft1):
        print("This record already exists")
    elif not aircrafts_obj.is_valid(aircraft1):
        print("The data you entered is invalid")
    else:
        aircrafts_obj.create_record(aircraft1)
        print(f"Aircraft Type {type_name} created for {iata_code}")

        total_seats = 0
        for cabin in cabin_configurations:
            seat_rows = cabin[1].split("-")
            last_seat = 0
            for seat_row in seat_rows:
                last_seat += int(seat_row)
            no_of_seats = last_seat * (int(cabin[3]) - int(cabin[2]) + 1)
            total_seats += no_of_seats

            print(f"Cabin Class {cabin[0]} - Seat {cabin[2]}A to {cabin[2]}{chr(ord('A') + last_seat - 1)} through"
                  f" {cabin[3]}A to {cabin[3]}{chr(ord('A') + last_seat - 1)}, {no_of_seats} seats")


def create_flight():
    airline_iata = input("Airline IATA Code - ")
    outbound_flight_no = input("Outbound Flight Number - ")
    return_flight_no = input("Return Flight Number - ")
    o_airport_iata = input("Origin Airport IATA code - ")
    d_airport_iata = input("Destination Airport IATA code - ")
    departure_date_time = input("Departure Date/Time - ")
    flight_time = input("Flight Time - ")
    stopover_duration = input("Stopover Duration - ")
    aircraft_type = input("Aircraft Type - ")

    cabin_classes = aircrafts_obj.get_cabins(airline_iata, aircraft_type)
    print("Fare Amount:")
    fare_amount = []
    for cabin_class in cabin_classes:
        price = int(input(f"Cabin Class {cabin_class} - $"))
        class_fare = [cabin_class, price]
        fare_amount.append(class_fare)

    flight1 = Flight(airline_iata, outbound_flight_no, return_flight_no, o_airport_iata, d_airport_iata,
                     departure_date_time, flight_time, stopover_duration, aircraft_type, fare_amount)

    if flights_obj.is_exist(flight1):
        print("This Flight already exists")
    else:
        flights_obj.create_record(flight1)
        print("Flight is created successfully")

    # flights_obj.display()
    # Uncomment above line if you want to see created flight in the list


def search_book_flights():
    trip_type = input("Trip Type - ")
    origin = input("Origin - ")
    destination = input("Destination - ")
    departure_date = input("Departure Date - ")
    cabin_class = input("Cabin Class - ")
    num_of_passengers = int(input("Number of Passengers - "))

    tickets = Tickets(trip_type, origin, destination, departure_date, cabin_class, num_of_passengers)
    matching_flights = tickets.find_direct_flights(flights_obj)

    # Stop over paths
    stop_over_paths = tickets.find_stopover_flights(flights_obj)

    result_count = 0

    for path in stop_over_paths:
        result_count += 1
        print(f"\nResult {result_count}")

        sum_cost = 0
        iteration = 0
        for flight in path:
            iteration += 1
            cost = flight.display_flight_details(cabin_class)
            sum_cost += cost

        print(f"\t{iteration-1} stopover, Total Fare ${sum_cost * num_of_passengers}")

    for flight in matching_flights:
        result_count += 1
        print(f"\nResult {result_count}")
        cost = flight[0].display_flight_details(cabin_class)
        print(f"\t0 stopover, Total Fare ${cost * num_of_passengers}")

    all_flights_paths = stop_over_paths
    all_flights_paths.extend(matching_flights)
    matching_flights.extend(stop_over_paths)
    selection = int(input("Select Flight – Result: "))
    while selection < 1 or selection > len(all_flights_paths):
        selection = int(input("Invalid input. Select Flight – Result: "))

    seats = []
    for i in range(num_of_passengers):
        seat = input(f"Select Seat for Passenger {i + 1} : ")
        seats.append(seat)

    tickets.set_seat_options(selection - 1, seats)
    selected_flight = all_flights_paths[selection - 1][0]

    selected_aircraft = aircrafts_obj.get_air_craft(selected_flight.aircraft_type, selected_flight.airline_iata)

    tickets.check_avaiability(selected_aircraft.cabin_configuration)


main_menu = '''

Press 1 - to Create Airline
Press 2 - to Create Aircraft Type
Press 3 - to Create Flight
Press 4 - to Search and Book a Flight

Press 0 - to Quit the Programme

'''
print(main_menu)
choice = int(input("Press the key - "))

while choice != 0:
    if choice == 1:
        create_airline()

    elif choice == 2:
        create_aircraft_type()

    elif choice == 3:
        create_flight()

    elif choice == 4:
        search_book_flights()

    print(main_menu)
    choice = int(input("Press the key - "))

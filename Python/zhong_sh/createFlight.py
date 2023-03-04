from datetime import datetime, timedelta

flights = [["SQ", "123", "321", "SIN", "NRT", "5 Dec 22, 10:00 AM", "6 hour 30 minute", "3 hour", "Boeing 747",
            [
                ['F', 2000],
                ['J', 1000],
                ['Y', 500]
            ]
            ],

           ["SQ", "456", "654", "SYD", "SIN", "4 Dec 22, 10:00 PM", "8 hour 0 minute", "2 hour", "Boeing 747",
            [
                ["F", 1500],
                ["J", 750],
                ["Y", 300],
            ]
            ],

           ["SQ", "789", "987", "SYD", "NRT", "5 Dec 22, 09:00 AM", "14 hour 0 minute", "2 hour", "Boeing 747",
            [
                ['F', 3500],
                ['J', 2500],
                ['Y', 1500]
            ]
            ],

           ["QF", "789", "987", "SYD", "NRT", "5 Dec 22, 01:00 PM", "14 hour 30 minute", "2 hour", "Boeing 747",
            [
                ['F', 3200],
                ['J', 2200],
                ['Y', 1200]
            ]
            ],

           ["SQ", "123", "321", "SIN", "NRT", "12 Dec 22, 10:00 AM", "6 hour 30 minute", "3 hour", "Boeing 747",
            [
                ['F', 2000],
                ['J', 1000],
                ['Y', 500]
            ]
            ],

           ["SQ", "456", "654", "SYD", "SIN", "11 Dec 22, 10:00 PM", "8 hour 0 minute", "2 hour", "Boeing 747",
            [
                ['F', 1500],
                ['J', 750],
                ['Y', 300]
            ]
            ],

           ["SQ", "789", "987", "SYD", "NRT", "12 Dec 22, 09:00 AM", "14 hour 0 minute", "2 hour", "Boeing 747",
            [
                ['F', 3500],
                ['J', 2500],
                ['Y', 1500]
            ]
            ],

           ["QF", "789", "987", "SYD", "NRT", "12 Dec 22, 01:00 PM", "14 hour 30 minute", "2 hour", "Boeing 747",
            [
                ['F', 3200],
                ['J', 2200],
                ['Y', 1200]
            ]
            ]

           ]
# Flight class, has association relationship with the Passenger class


class Flight:
    def __init__(self, airline_iata, outbound_flight_no, return_flight_no, o_airport_iata, d_airport_iata,
                 departure_date_time, flight_time, stopover_duration, aircraft_type, fare):
        self.airline_iata = airline_iata
        self.outbound_flight_no = outbound_flight_no
        self.return_flight_no = return_flight_no
        self.o_airport_iata = o_airport_iata
        self.d_airport_iata = d_airport_iata
        self.departure_date_time = departure_date_time
        self.flight_time = flight_time
        self.stopover_duration = stopover_duration
        self.aircraft_type = aircraft_type
        self.fare = fare

    def __str__(self):
        "Q789, SYD to NRT, Depart 5 Dec 22 9:00 AM, Arrive 5 Dec 22 11:00 PM, Class Y $1,500"
        hours = int(self.flight_time.split("hour")[0])
        mins = int(self.flight_time.split("hour")[1].split("minute")[0])

        flight_arrive_datetime = datetime.strptime(self.departure_date_time, "%d %b %y, %I:%M %p") + timedelta(
            minutes=hours * 60 + mins)

        arrive_datetime_str = datetime.strftime(flight_arrive_datetime, "%d %b %y, %I:%M %p")
        # print(arrive_datetime_str)

        return self.airline_iata + self.outbound_flight_no + ", " + \
               self.o_airport_iata + " to " + self.d_airport_iata + ", Depart " + self.departure_date_time + ", Arrive " + \
               arrive_datetime_str

    def display_flight_details(self, class_type):
        hours = int(self.flight_time.split("hour")[0])
        mins = int(self.flight_time.split("hour")[1].split("minute")[0])

        flight_arrive_datetime = datetime.strptime(self.departure_date_time, "%d %b %y, %I:%M %p") + timedelta(
            minutes=hours * 60 + mins)

        arrive_datetime_str = datetime.strftime(flight_arrive_datetime, "%d %b %y, %I:%M %p")

        cost = 0
        for element in self.fare:
            if element[0] == class_type:
                cost = element[1]
                break

        print("\t" + self.airline_iata + str(self.outbound_flight_no) + ", " + \
              self.o_airport_iata + " to " + self.d_airport_iata + ", Depart " + self.departure_date_time + ", Arrive " + \
              arrive_datetime_str + ", Class " + class_type + " $" + str(cost))

        return cost


class Flights:
    def __init__(self):
        self.flights = []
        for flight in flights:
            temp = Flight(flight[0], flight[1], flight[2], flight[3], flight[4], flight[5], flight[6], flight[7],
                          flight[8], flight[9])
            self.flights.append(temp)

    def is_exist(self, flight):
        is_exist = False
        for cur_flight in self.flights:
            if cur_flight.airline_iata == flight.airline_iata and cur_flight.outbound_flight_no == flight.outbound_flight_no and cur_flight.departure_date_time == flight.departure_date_time:
                is_exist = True
                break
        return is_exist

    def create_record(self, flight):
        self.flights.append(flight)

    def display(self):
        for flight in self.flights:
            print(flight)

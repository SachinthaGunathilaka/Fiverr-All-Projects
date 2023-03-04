from createFlight import Flights
from datetime import datetime, timedelta

# Created Passenger class, Association used with the Flight class


class Passengers:
    def __init__(self, trip_type, origin, destination, departure_date, cabin_class, no_of_passengers):
        self.trip_type = trip_type
        self.origin = origin
        self.destination = destination
        self.departure_date = departure_date
        self.cabin_class = cabin_class
        self.no_of_passengers = no_of_passengers

    def find_direct_flights(self, flights_obj):

        results = []
        for flight in flights_obj.flights:
            flight_departure_date = datetime.strptime(flight.departure_date_time, "%d %b %y, %I:%M %p").date()
            passenger_departure_date = datetime.strptime(self.departure_date, "%d %b %y").date()
            if self.origin == flight.o_airport_iata and self.destination == flight.d_airport_iata and flight_departure_date == passenger_departure_date:
                # print(flight)
                for cabin in flight.fare:
                    if cabin[0] == self.cabin_class:
                        results.append([flight])

        return results

    def find_stopover_flights(self, flights_obj):


        result = []
        departure_date = datetime.strptime(self.departure_date, "%d %b %y").date()

        for flight in flights_obj.flights:
            temp_result = [flight]
            if self.origin != flight.o_airport_iata or self.destination == flight.d_airport_iata:
                continue

            # connecting_flights = []

            for temp_flight in flights_obj.flights:
                if temp_flight.outbound_flight_no != flight.outbound_flight_no and flight.airline_iata == temp_flight.airline_iata:
                    if flight.d_airport_iata == temp_flight.o_airport_iata:

                        hours = int(flight.flight_time.split("hour")[0])
                        mins = int(flight.flight_time.split("hour")[1].split("minute")[0])

                        flight_arrive_datetime = datetime.strptime(flight.departure_date_time,
                                                                   "%d %b %y, %I:%M %p") + timedelta(
                            minutes=hours * 60 + mins)

                        connecting_flight_departure_datetime = datetime.strptime(temp_flight.departure_date_time,
                                                                                 "%d %b %y, %I:%M %p")

                        if departure_date < connecting_flight_departure_datetime.date():
                            continue

                        if flight_arrive_datetime <= connecting_flight_departure_datetime:
                            temp_result.append(temp_flight)

                            if temp_flight.d_airport_iata == self.destination:
                                connecting_flight_departure_date = connecting_flight_departure_datetime.date()
                                if departure_date == connecting_flight_departure_date:
                                    result.append(temp_result)
                        # connecting_flights.append(temp_flight)

            return result
            # for path in result:
            #     print("Path\n\n")
            #     for flight in path:
            #         print(flight)
            # print(flight.airline_iata + flight.outbound_flight_no)
            # print("---------------------")
            # if len(connecting_flights) == 0:
            #     print("Not Available")
            #
            # else:
            #     for flight in connecting_flights:
            #         print(flight)
            #
            # print("\n\n")

            #
            # while True:
            #     for flight_1 in flights_obj:
            #         flight_departure_date = datetime.strptime(flight_1[5], "%d %b %y, %I:%M %p").date()
            #         passenger_departure_date = datetime.strptime(self.departure_date, "%d %b %y").date()
            #         if origin == flight_1[3] and self.destination == flight_1[4] and flight_departure_date == passenger_departure_date:
            #             result.append(flight)
            #             result.append(flight_1)
            #             stopover_count += 1
            #         elif origin == flight_1[3] and self.destination != flight_1[4]:
            #             origin = flight_1[4]
            #             stopover_count += 1

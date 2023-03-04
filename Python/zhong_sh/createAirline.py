airlines = [
    ["SQ", "Singapore Airlines"],
    ["QF", "Qantas"]
]


#
# aircraft_type = [
#
#     {
#         "airline": "SQ",
#         "type": "Boeing 747",
#         "configuration": [
#             ['F', 1 - 1 - 1, 1, 10],
#             ['J', 2 - 2 - 2, 11, 20],
#             ['Y', 3 - 4 - 3, 21, 50]
#         ]
#     },
#     {
#         "airline": "QF",
#         "type": "Boeing 747",
#         "configuration": [
#             ['F', 1 - 1 - 1, 1, 10],
#             ['J', 2 - 2 - 2, 11, 20],
#             ['Y', 3 - 4 - 3, 21, 50]
#         ]
#     }
#
# ]
#
#
# Flights = [["SQ", "123", "321", "SIN", "NRT", "5 Dec 22 10:00 AM", "6 hour 30 minute", "3 hour", "Boeing 747",
#             [
#                 ['F', 2000],
#                 ['J', 1000],
#                 ['Y', 500]
#             ]
#             ],
#
#            ["SQ", "456", "654", "SYD", "SIN", "4 Dec 22 10:00 PM", "8 hour 0 minute", "2 hour", "Boeing 747",
#             [
#                 ["F", 1500],
#                 ["J", 750],
#                 ["Y", 300],
#             ]
#             ],
#
#            ["SQ", "789", "987", "SYD", "NRT", "5 Dec 22, 09:00 AM", "14 hour 0 minute", "2 hour", "Boeing 747",
#             [
#                 ['F', 3500],
#                 ['J', 2500],
#                 ['Y', 1500]
#             ]
#             ],
#
#            ["QF", "789", "987", "SYD", "NRT", "5 Dec 22, 01:00 PM", "14 hour 30 minute", "2 hour", "Boeing 747",
#             [
#                 ['F', 3200],
#                 ['J', 2200],
#                 ['Y', 1200]
#             ]
#             ],
#
#            ["SQ", "123", "321", "SIN", "NRT", "12 Dec 22 10:00 AM", "6 hour 30 minute", "3 hour", "Boeing 747",
#             [
#                 ['F', 2000],
#                 ['J', 1000],
#                 ['Y', 500]
#             ]
#             ],
#
#            ["SQ", "456", "654", "SYD", "SIN", "11 Dec 22 10:00 PM", "8 hour 0 minute", "2 hour", "Boeing 747",
#             [
#                 ['F', 1500],
#                 ['J', 750],
#                 ['Y', 300]
#             ]
#             ],
#
#            ["SQ", "789", "987", "SYD", "NRT", "12 Dec 22", "09:00 AM", "14 hour 0 minute", "2 hour", "Boeing 747",
#             [
#                 ['F', 3500],
#                 ['J', 2500],
#                 ['Y', 1500]
#             ]
#             ],
#
#            ["QF", "789", "987", "SYD", "NRT", "12 Dec 22", "01:00 PM", "14 hour 30 minute", "2 hour", "Boeing 747",
#             [
#                 ['F', 3200],
#                 ['J', 2200],
#                 ['Y', 1200]
#             ]
#             ]
#
#            ]
#

class Airline:
    def __init__(self, iata_code, name):
        self.iata_code = iata_code
        self.name = name

    def __str__(self):
        return self.iata_code + ", " + self.name


class Airlines:
    def __init__(self):
        self.airlines_list = []
        for airline in airlines:
            air = Airline(airline[0], airline[1])
            self.airlines_list.append(air)

    def is_exist(self, airline):
        is_exist = False
        for current_airline in self.airlines_list:
            if current_airline.iata_code in airline.iata_code:
                is_exist = True
                break
        return is_exist

    def create_record(self, airline):
        self.airlines_list.append(airline)

    def display(self):
        for airline in self.airlines_list:
            print(airline)


aircraft_types = [["SQ", "Boeing 747", [
    ['F', "1-1-1", '1', '10'],
    ['J', "2-2-2", '11', '20'],
    ['Y', "3-4-3", '21', '50']
]
                   ],
                  ["QF", "Boeing 747", [
                      ['F', "1-1-1", '1', '10'],
                      ['J', "2-2-2", '11', '20'],
                      ['Y', "3-4-3", '21', '50']
                  ]
                   ]
                  ]

# Created Aircraft class


class Aircraft:
    def __init__(self, iata_code, type_name, cabin_configuration):
        self.iata_code = iata_code
        self.type_name = type_name
        self.cabin_configuration = cabin_configuration

    def __str__(self):
        return self.iata_code + ", " + self.type_name + ", " + str(self.cabin_configuration)


class Aircrafts:
    def __init__(self):
        self.aircrafts = []
        for aircraft in aircraft_types:
            temp = Aircraft(aircraft[0], aircraft[1], aircraft[2])
            self.aircrafts.append(temp)

    def get_air_craft(self, type_name, iata_code):
        for aircraft in self.aircrafts:
            if aircraft.type_name == type_name and aircraft.iata_code == iata_code:
                return aircraft

    def is_exist(self, aircraft):
        is_exist = False
        for cur_aircraft in self.aircrafts:
            if cur_aircraft.type_name == aircraft.type_name and cur_aircraft.iata_code == aircraft.iata_code:
                is_exist = True
                break
        return is_exist

    def is_valid(self, aircraft):
        is_valid = True
        for cabin in aircraft.cabin_configuration:
            if cabin[0] not in ["F", "J", "W", "Y"]:
                is_valid = False
                break
        return is_valid

    def create_record(self, aircraft):
        self.aircrafts.append(aircraft)

    def get_cabins(self, airline_iata, aircraft_type):
        cabin_classes = []
        for aircraft in self.aircrafts:
            if aircraft.iata_code == airline_iata and aircraft.type_name == aircraft_type:
                for data in aircraft.cabin_configuration:
                    cabin_classes.append(data[0])

        return cabin_classes

    def display(self):
        for aircraft in self.aircrafts:
            print(aircraft)

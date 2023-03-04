class weatherStation:
    def __init__(self, location, temperature, rain, wind_speed, wind_direction, air_quality, co2, humidity):
        self.location = location
        self.temperature = temperature
        self.rain = rain
        self.wind_speed = wind_speed
        self.wind_direction = wind_direction
        self.air_quality = air_quality
        self.co2 = co2
        self.humidity = humidity

    def getLocation(self):
        return self.location

    def getTemperature(self):
        return self.temperature

    def getRain(self):
        return self.rain

    def getWindSpeed(self):
        return self.wind_speed

    def getWindDirection(self):
        return self.wind_direction

    def getAirQuality(self):
        return self.air_quality

    def getCO2(self):
        return self.co2

    def getHumidity(self):
        return self.humidity

    def setLocation(self, location):
        self.location = location

    def setTemperature(self, temperature):
        self.temperature = temperature

    def setRain(self, rain):
        self.rain = rain

    def setWindSpeed(self, wind_speed):
        self.wind_speed = wind_speed

    def setWindDirection(self, wind_direction):
        self.wind_direction = wind_direction

    def setAirQuality(self, air_quality):
        self.air_quality = air_quality

    def setCO2(self, co2):
        self.co2 = co2

    def setHumidity(self, humidity):
        self.humidity = humidity

    def celsiusToFahrenheit(self, celsius):
        return (celsius * 1.8) + 32

    def mphToKm(self, mph):
        return mph * 1.60934

    def display(self):
        print(f"\n\tLocation : {self.location}\n"
              f"\tTemperature : {self.celsiusToFahrenheit(self.temperature)}\n"
              f"\tRain : {self.rain}\n"
              f"\tWind Speed : {self.mphToKm(self.wind_speed)}\n"
              f"\tWind Direction : {self.wind_direction}\n"
              f"\tAir Quality : {self.air_quality}\n"
              f"\tCO2 : {self.co2}\n"
              f"\tHumidity : {self.humidity}")

def isfloat(value):
    try:
        float(value)
        return True
    except ValueError:
        return False

stop = False
stations = []
print("\nWEATHER STATION\n"
      "----------------\n")

while not stop:
    location = input("Enter location : ")
    temperature = input("Enter temperature : ")
    while not isfloat(temperature):
        print("Invalid value")
        temperature = input("Enter temperature : ")

    rain = input("Enter rain : ")

    wind_speed = input("Enter wind speed : ")
    while not isfloat(wind_speed):
        print("Invalid value")
        wind_speed = input("Enter wind speed : ")

    wind_direction = input("Enter wind_direction : ")
    air_quality = input("Enter air_quality : ")
    co2 = input("Enter co2 : ")
    humidity = input("Enter humidity : ")

    station = weatherStation(location, float(temperature), rain, float(wind_speed), wind_direction, air_quality, co2, humidity)
    stations.append(station)

    choice = input("Do you want to add more stations ? (y/n)").lower()
    if choice == "n":
        stop = True


print("\nWEATHER STATIONS INFORMATION\n"
      "----------------------------")
for station in stations:
    station.display()
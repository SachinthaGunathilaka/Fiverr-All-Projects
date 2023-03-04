from organized.package.place.Carriage import Carriage


class BoxCar(Carriage):
    next_ID = 0

    def __init__(self, tare, length):
        super().__init__(tare, length)
        self.id = "BC-" + str(BoxCar.next_ID)
        BoxCar.next_ID += 1

    def add_cargo(self, type, weight):
        type = type.lower()
        if type in ["cattle", "paper", "food"]:
            if self.type == "" or self.type == type:
                self.type = type
                self.set_volume(self.volume + weight)

    def __str__(self):
        return f"[Box Car]ID:{self.id} Cargo type: {self.type} Volume: {self.volume}"

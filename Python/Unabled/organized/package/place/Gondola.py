from organized.package.place.Carriage import Carriage


class Gondola(Carriage):
    next_ID = 0

    def __init__(self, tare, length):
        super().__init__(tare, length)

        self.id = "GD-" + str(Gondola.next_ID)
        self.volume = 0
        Gondola.next_ID += 1

    def add_cargo(self, type, weight):
        type = type.lower()
        if type in ["coal", "gravel", "metalore"]:
            if self.type == "" or self.type == type:
                self.type = type
                self.set_volume(self.volume + weight)

    def __str__(self):
        return f"[Gondola]ID:{self.id} Cargo type: {self.type} Volume: {self.volume}"

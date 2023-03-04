import json
import math


class TrainManager:
    def __init__(self):
        self.trains = []

    def add_train(self, train):
        self.trains.append(train)

    def remove_train(self, id):
        index = -1
        for i in range(len(self.trains)):
            if self.trains[i].id == id:
                index = i
                break

        if index == -1:
            raise ValueError("Couldn't find such train in the train list!")

        del self.trains[index]

    def avg_mean_carriages(self):
        total_mean_carriages = 0
        for train in self.trains:
            total_mean_carriages += train.get_mean_carriages()

        return round(total_mean_carriages / len(self.trains), 2)

    def std_carriage(self):
        carriages = []
        for train in self.trains:
            carriages.append(train.get_mean_carriages())

        var = sum(pow(x - self.avg_mean_carriages(), 2) for x in carriages) / len(carriages)  # variance
        return round(math.sqrt(var), 2)

    def export_as_json(self, filename):

        trains = []
        for train in self.trains:
            trains.append({train.id: f"{train}"})

        result = {"Train Manager": trains}
        with open(filename, 'w') as fp:
            json.dump(result, fp)

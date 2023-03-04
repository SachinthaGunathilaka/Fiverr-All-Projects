class Min:
    def min3(self, value1, value2, value3):
        if value1 < value2 and value1 < value3:
            return value1

        if value2 < value3:
            return value2

        return value3

    def min5(self, value1, value2, value3, value4, value5):
        set1_min = self.min3(value1, value2, value3)
        return self.min3(value4, value5, set1_min)


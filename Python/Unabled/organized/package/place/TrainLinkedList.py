from organized.package.place.Node import Node


class TrainLinkedList:
    next_ID = 0

    def __init__(self):
        self.id = "TrainLinkedList-" + str(TrainLinkedList.next_ID)
        self.head = None
        TrainLinkedList.next_ID += 1

    def add_first(self, carriage):
        newNode = Node(carriage)
        newNode.next = self.head
        self.head = newNode

    def add_last(self, carriage):
        newNode = Node(carriage)

        if self.head is None:
            self.head = newNode

        else:
            temp = self.head
            while temp.next is not None:
                temp = temp.next

            temp.next = newNode

    def add_after(self, reference_carriage, carriage):

        newNode = Node(carriage)
        if self.head is None:
            return

        temp = self.head
        isFind = False
        while temp is not None:
            if temp.carriage.id == reference_carriage.id:
                isFind = True
                break
            temp = temp.next

        if not isFind:
            return
        newNode.next = temp.next
        temp.next = newNode

    def add_before(self, reference_carriage, carriage):
        newNode = Node(carriage)
        if self.head is None:
            return

        if self.head.carriage.id == reference_carriage.id:
            newNode.next = self.head
            self.head = newNode

        else:

            prev = None
            temp = self.head

            while temp.next is not None and temp.carriage.id != reference_carriage.id:
                prev = temp
                temp = temp.next

            if prev is None:
                return
            newNode.next = prev.next
            prev.next = newNode

    def remove_carriage(self, carriage):
        if self.head is None:
            return

        if self.head.carriage.id == carriage.id:
            self.head = self.head.next


        else:
            prev = self.head
            current = self.head.next

            while current is not None:
                if current.carriage.id == carriage.id:
                    break

                prev = current
                current = current.next

            if current is not None:
                prev.next = current.next

    def remove_carriage_by_position(self, position):
        if self.head is None or position < 0:
            return

        index = 0
        current = self.head
        previous = None
        while current.next and index < position:
            previous = current
            current = current.next
            index += 1
        if index < position:
            return
        elif index == 0:
            self.head = self.head.next
        else:
            previous.next = current.next

    def remove_end(self):
        if self.head is None:
            return

        if self.head.next is None:
            self.head = None

            return

        temp = self.head
        while temp.next.next is not None:
            temp = temp.next

        temp.next = None

    def remove_first(self):
        if self.head is None:
            return

        self.head = self.head.next

    def find_carriage_by_id(self, id):
        temp = self.head
        while temp is not None:
            if temp.carriage.id == id:
                return temp.carriage
            temp = temp.next

        return None

    def get_carriage_count(self):
        count = 0
        temp = self.head
        while temp is not None:
            count += 1
            temp = temp.next

        return count

    def get_mean_carriages(self):
        total = 0
        temp = self.head
        while temp is not None:
            total += temp.carriage.volume
            temp = temp.next

        return total / self.get_carriage_count()

    def __str__(self):
        display_text = ""
        temp = self.head
        if temp is None:
            return "None"

        display_text += f"{temp}"
        while temp.next is not None:
            temp = temp.next
            display_text += " -> "
            display_text += f"{temp}"

        display_text += " -> None"

        return display_text

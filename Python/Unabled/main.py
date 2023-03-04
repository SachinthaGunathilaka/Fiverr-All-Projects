from organized.package.place.BoxCar import BoxCar
from organized.package.place.Cistern import Cistern
from organized.package.place.Gondola import Gondola
from organized.package.place.Hopper import Hopper
from organized.package.place.TrainLinkedList import TrainLinkedList
from organized.package.place.TrainManager import TrainManager


train = TrainLinkedList()

# First train
box_cart = BoxCar(tare=10, length=200)
cistern = Cistern(tare=10, length=250)
gondola = Gondola(tare=15, length=350)
hopper = Hopper(tare=20, length=120)
box_cart.add_cargo('cattle', 20)
cistern.add_cargo('oil', 15)
hopper.add_cargo('sand', 20)
gondola.add_cargo('coal', 20)

# Carriage print out
print(box_cart)
print(cistern)
print(hopper)
print(gondola)


train.add_first(box_cart)
train.add_last(cistern)
print(train)
train.add_after(box_cart, gondola)
train.add_before(gondola, hopper)
train.remove_carriage(box_cart)
print(train.get_carriage_count())


# Second train
second_train = TrainLinkedList()
box_cart1 = BoxCar(50, 200)
box_cart1.add_cargo('food', 30)
cistern1 = Cistern(10, 250)
gondola1 = Gondola(15, 350)
cistern1.add_cargo('oil', 30)
gondola1.add_cargo('coal', 21)

second_train.add_first(box_cart1)
second_train.add_last(gondola1)
second_train.add_after(box_cart1, cistern1)

train_manager = TrainManager()
train_manager.add_train(train)
train_manager.add_train(second_train)
print(train_manager.avg_mean_carriages())
print(train_manager.std_carriage())


train_manager.export_as_json('temp.json')

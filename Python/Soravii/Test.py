from hw2 import *
pie = Pizza()
print(pie)


# Pizza('M',set())
pie.setSize('L')
print(pie.getSize())
# 'L'
pie.addTopping('pepperoni')
pie.addTopping('anchovies')
pie.addTopping('mushrooms')
print(pie)
# Pizza('L',{'anchovies', 'mushrooms', 'pepperoni'})
pie.addTopping('pepperoni')
print(pie)
# Pizza('L',{'anchovies', 'mushrooms', 'pepperoni'})
pie.removeTopping('anchovies')
print(pie)
# Pizza('L',{'mushrooms', 'pepperoni'})
print(pie.price())
# 16.65
pie2 = Pizza('L',{'mushrooms','pepperoni'})
print(pie2)
# Pizza('L',{'mushrooms', 'pepperoni'})
print(pie==pie2)
# True

orderPizza()
orderPizza()
orderPizza()

CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = bard.o LinkedList.o Node.o

Bard: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o $@ $^

clean: 
	rm -f *.o bard

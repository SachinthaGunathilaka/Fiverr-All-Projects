CC = g++
CFLAGS  = -g -Wall

TARGET = dijkstra

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	$(RM) $(TARGET)

run:
	./dijkstra input.txt AD CAN
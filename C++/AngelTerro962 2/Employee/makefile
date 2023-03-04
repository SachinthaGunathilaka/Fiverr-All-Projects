#
# Makefile for dna_main
#

#
# Define variables and flags
#
CC = g++
CXXFLAGS = -c
BINARY   = simple_test
TEMPSRC  = $(wildcard *.cpp) 
SOURCES  = $(filter-out $(BINARY).cpp, $(TEMPSRC))
OBJECTS  = $(SOURCES:.cpp=.o)
INCLUDES = $(SOURCES:.cpp=.h)


#
# default rule all builds BINARY which is simple_test
#
all: $(BINARY)

#
# Rule to build BINARY - links all objects (*.o) into the BINARY
# 	
$(BINARY): $(OBJECTS) $(INCLUDES) $(BINARY).o
	$(CC) $(BINARY).o $(OBJECTS) -o $(BINARY)

#
# Rule to build any *.o file from it's *.cpp file.
#
.cpp.o:  
	$(CC) $(CXXFLAGS) $< -o $@

#
# Rule to build main program object file with dependencies
#
$(BINARY).o: $(BINARY).cpp $(INCLUDES)
	$(CC) $(CXXFLAGS) $< -o $@

#
# Rule to clean everything so that only source files remain.
#
clean:
	-rm -f $(OBJECTS) $(BINARY)

.PHONY: all clean

#
# Dependencies: all *.o are dependent on same named *.cpp and *.h
#
%.o: %.cpp %.h Employee.h
$(BINARY): $(INCLUDES)

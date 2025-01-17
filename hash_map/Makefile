CC = g++
CFLAGS = --std=gnu++2b -Wall

EXEC = main

OBJECTS = main.o

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJECTS)

main.o: main.cpp HashMap.hpp
	$(CC) $(CFLAGS) -c main.cpp

.PHONY: clean all

all: $(EXEC)

clean:
	rm -f $(EXEC) $(OBJECTS)

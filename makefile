CC=g++
CFLAGS=-Wall -g -c -std=c++11
LFLAGS=-Wall -g
MODULES=memory
INCLUDE=./container-sequential
OBJECTS=$(wildcard ./objects/*.o)
#	$<	the name of the prerequisite
#	$@	the name of the target

.PHNOY : link
link : compile
	$(CC) $(LFLAGS) $(OBJECTS) -o run

.PHNOY : compile
compile : $(OBJECTS)

objects/main.o: main.cpp container-sequential/memory.hpp
	$(CC) $(CFLAGS) main.cpp -I $(INCLUDE) -o $@

objects/test.o : test/test.cpp
	$(CC) $(CFLAGS) $< -o $@

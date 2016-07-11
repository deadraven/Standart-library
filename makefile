#	$<	the name of the prerequisite
#	$@	the name of the target
CC=g++
CFLAGS= -Wall -g -c -std=c++11
LFLAGS= -Wall -g
MODULES= memory
INCLUDE = $(addprefix ./, $(MODULES))
OBJECTS=$(wildcard ./objects/*.o)

.PHNOY : link
link : compile
	$(CC) $(LFLAGS) $(OBJECTS) -o main

.PHNOY : compile
compile : $(OBJECTS)

objects/main.o: main.cpp memory/memory.h
	$(CC) $(CFLAGS) main.cpp -I $(INCLUDE) -o $@

objects/test.o : test/test.cpp
	$(CC) $(CFLAGS) $< -o $@

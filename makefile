CC=g++
CFLAGS=-Wall -g -c -std=c++11
LFLAGS=-Wall -g
INCLUDE=./container-sequential
MODULES=main
OBJECTS=$(addprefix ./objects/, $(addsuffix .o,$(MODULES)))
#	$<	the name of the prerequisite
#	$@	the name of the target

.PHNOY : link
link : compile
	$(CC) $(LFLAGS) $(OBJECTS) -o run

.PHNOY : compile
compile : $(OBJECTS)

objects/main.o: main.cpp container-sequential/array.hpp
	$(CC) $(CFLAGS) main.cpp -I $(INCLUDE) -o $@

objects/test.o : array.cpp
	$(CC) $(CFLAGS) $< -o $@

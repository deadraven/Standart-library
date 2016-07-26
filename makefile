CXX=g++
CXXFLAGS=-Wall -g -std=c++11
LFLAGS=-Wall -g
OUTPUT=run
INCLUDE=-I./container-sequential -I./tester
VPATH=tester container-sequential
OBJECT_DIR=./objects/
vpath %.o $(OBJECT_DIR)


MODULES=main
OBJECT_LIST=$(addprefix $(OBJECT_DIR), $(addsuffix .o,$(MODULES)))
OBJECT_OUTPUT=$(addprefix $(OBJECT_DIR),$@)
#$(addprefix ./objects/, $(addsuffix .o,$(MODULES)))
#	$<	the name of the prerequisite
#	$@	the name of the target

.PHONY : link
link : clearscreen compile
	$(CXX) $(LFLAGS) $(OBJECT_LIST) -o run

.PHONY : compile
compile : main.o

.PHONY : main
main.o: main.cpp array.hpp tester-container.hpp
	$(CXX) $(CXXFLAGS) main.cpp $(INCLUDE) -c -o $(OBJECT_OUTPUT)




.PHNOY : memory
memory : container-sequential/test-memory.cpp container-sequential/memory.hpp
	$(CC) $(CFLAGS) $< -I $(INCLUDE) -o $(OUTPUT)

.PHNOY : array
array : container-sequential/test-array.cpp container-sequential/array.hpp
	$(CC) $(CFLAGS) $< -I $(INCLUDE) -o $(OUTPUT)

.PHONY : clearscreen
clearscreen :
	clear

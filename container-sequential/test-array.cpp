#include <iostream>
#include "memory.hpp"
#include "array.hpp"

int main(int argc, const char* argv[]){
	array<int,10> a(0);
std::cout << "size:" << a.max_size() << std::endl;
	return 0;
}

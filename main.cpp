#include <iostream>
#include <vector>
#include <sstream>
#include "./container-sequential/memory.hpp"
//#include "./container-sequential/array.hpp"
#include "./tester/tester-container.hpp"

int main(int argc, const char* argv[]){
	empty_construction<memory<int>> test1 {flags::run||flags::print};
//	Tester_container<memory<int>> test {};
//	test.empty_construction().print();
//	test.zero_construction().print();
//	test.negative_construction().print();
//	test.title(test.Zero_Construction).zero_construction();

//	test.negative_construction();
//	std::stringstream a;
//	a << "test";
//	std::cout << a.str();

	return 0;
}

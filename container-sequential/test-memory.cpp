#include <utility>
#include <iostream>
#include <string>
#include <iomanip>
#include "memory.hpp"


int main(int argc, const char* argv[]){
using std::cout;
using std::endl;
auto pad = std::setw(24);




{	cout << endl << "=== Positive construction ===" << endl;
	memory<int> a {5};
	cout << pad << "a {5} = " << a << endl;}

{	cout << endl << "=== Copy construction ===" << endl;
	memory<int> a {5};
	cout << pad << "a = " << a << endl;
	memory<int> b {a};
	cout << pad << "b {a} = " << b << endl;}

{	cout << endl << "=== Move construction ===" << endl;
	memory<int> a {5};
	cout << pad << "a = " << a << endl;
	memory<int> b {std::move(a)};
	cout << pad << "b {move(a)} = " << b << endl;
	cout << pad << "a = " << a << endl;}

{	cout << endl << "=== Iterator ===" << endl;
	memory<int> a {5};
	cout << pad << "a = " << a << endl;

	memory<int>::iterator begin {a.begin()};
	memory<int>::iterator end {a.end()};
	cout << pad << "begin() = " << begin << endl;
	cout << pad << "end() = " << end << endl;
	cout << pad << "*begin() = " << *begin << endl;
	cout << pad << "++begin() = " << ++begin << endl;
	cout << pad << "--end() = " << --end << endl;
	cout << pad << "begin()==begin() = " << (begin==begin) << endl;
	cout << pad << "begin()==end() = " << (begin==end) << endl;
	cout << pad << "begin()!=begin() = " << (begin!=begin) << endl;
	cout << pad << "begin()!=end() = " << (begin!=end) << endl;
	cout << pad << "begin()+1 = " << "compile error" << endl;
	cout << pad << "begin()+5 = " << "compile error" << endl;
	cout << pad << "end()-begin() = " << "compile error" << endl;

	cout << pad << "values = ";
	for (auto i=a.begin(); i!=a.end(); ++i )	cout << "  " << *i;
	std::cout << std::endl;}

{	cout << endl << "=== Slice construction ===" << endl;
	memory<int> a {5};
	cout << pad << "a = " << a << endl;
	memory<int>::iterator begin {++a.begin()};
	memory<int>::iterator end {--a.end()};
	cout << pad << "second = " << begin << endl;
	cout << pad << "last = " << end << endl;
	memory<int> b {begin,end};
//	cout << pad << "b {second,last} = " << b << endl;


}
	return 0;
}

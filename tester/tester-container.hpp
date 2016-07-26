#ifndef __Standart_Library__tester_container__
#define __Standart_Library__tester_container__

#include <algorithm>
#include <iterator>
#include <initializer_list>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>

enum class flags { run=1, print=2 };
template <class T> struct empty_construction {
	using container = T;
	std::string title {"Empty construction"};
	std::ostringstream report {};
	bool isRun(flags flag){	return ((flag & flags::run)==flags::run) ? true : false;	}
	empty_construction(flags flag=flags::run){
		if(isRun(flag)) run:run();
//		if(flag && flags::print) print();
	};
	int indent {24};
	void run(){
		container a {};
		report << std::setw(indent) << "a {} : " << a << std::endl;

	};
	void print(){	std::cout << "> " << title << ":" << std::endl << report.str();	};
};

template <class T> class Tester_container {
	public:
		using container = T;
		using self = Tester_container<T>;

		struct Report {
			Report(std::string input_title): title {input_title}	{};
			std::string title;
			std::ostringstream message {};
			void print(){	std::cout << "> " << title << ":" << std::endl << message.str();	};
		};

		Report empty_construction(){
			Report report {"Empty construction"};
			container a {};
			report.message << std::setw(indent) << "a {} : " << a << std::endl;
			return report;
		};
		Report zero_construction(){
			Report report {"Zero construction"};
			container a {0};
			report.message << std::setw(indent) << "a {0} : " << a << std::endl;
			return report;
		};
		Report negative_construction(int n = -5){
			Report report {"Negative construction"};
			container a {n};
			report.message << std::setw(indent) << "a {" << n << "} : " << a << std::endl;
			return report;
		};




	private:
		int indent = 24;
};
#endif

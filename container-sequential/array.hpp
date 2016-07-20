#ifndef __Standart_Library__array__
#define __Standart_Library__array__

#include <iostream>
#include "memory.hpp"

template <typename T, int N> class array {
	public:
		using value_type		= T;
		using reference			= T&;
		using const_reference	= const T&;
		using pointer			= T*;
		using const_pointer		= const T*;
		using difference_type	= std::ptrdiff_t;
		using size_type			= std::size_t;
		using container			= array<T,N>;

		array( value_type default_value)
			:_data{ new memory<T>(N) }
			{
				std::cout << *_data << std::endl;
				for ( int i=0; i<N; i++) (*_data)[i] = default_value;
				std::cout << *_data << std::endl;
			};
/*		array(std::initializer_list<T> source) //remove constructor from initializer list
			: memory(source.size())
			{ std::move( source.begin(), source.end(), iterator{_data}); };
*/
		~array()
			{ delete _data; };

		size_type		size() const											{ return _capacity; };
		int max_size() const { return _data->size(); };
	private:
		memory<T>*	_data;
		size_type	_capacity = N;
};
#endif

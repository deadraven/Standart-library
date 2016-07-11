#ifndef __Standart_Library__memory__
#define __Standart_Library__memory__
#include <algorithm>
#include <initializer_list>
#include <sstream>

template <typename T>
class memory {
	public:
		using value_type		= T;
		using reference			= T&;
		using const_reference	= const T&;
		using pointer			= T*;
		using const_pointer		= const T*;
		using difference_type	= std::ptrdiff_t;
		using size_type			= std::size_t;
		using container			= memory<T>;
	//Iterator
	class iterator {
		public:
						iterator(pointer p): _current{p}						{};
			iterator&	operator++()											{ _current++; return *this; };
			iterator&	operator--()											{ _current--; return *this; };
			reference	operator*()												{ return *_current; };
			bool		operator==(const iterator& b) const						{ return _current == b._current; };
			bool		operator!=(const iterator& b) const						{ return _current != b._current; };
		private:
			pointer		_current;
	};

	//Constructors
	memory(size_type n=0)
		: _data{n>0 ? new T[n] : nullptr}, _size {n>0 ? n : 0}
		{};
	memory(const container& source)
		: memory(source._size)
		{ std::copy( source.begin(), source.end(), iterator {_data}); };
	memory(container&& source) noexcept
		: memory()
		{ swap(source); };
	memory(std::initializer_list<T> source) //remove constructor from initializer list
		: memory(source.size())
		{ std::move( source.begin(), source.end(), iterator{_data}); };
	memory(iterator begin, iterator end)
		: memory( std::distance( begin, end))
		{ std::copy( begin, end, iterator {_data}); }
	~memory()
		{ delete[] _data; };

	void			swap(container& source);

	//Operators
	container&		operator=(const container& source) noexcept;
	container&		operator=(container&& source) noexcept;
	reference		operator[](int n)											{ return _data[n]; };
	const_reference	operator[](int n) const										{ return _data[n]; };

	//Iterator functions
	iterator		begin()														{ return iterator {_data}; };
	iterator		end()														{ return iterator {_data+_size}; };
	const iterator	begin() const												{ return iterator {_data}; };
	const iterator	end() const													{ return iterator {_data+_size}; };

	//Members
	size_type		size() const												{ return _size; };
	pointer			data()														{ return _data; };
	const_pointer	data() const												{ return _data; };

	friend std::ostream& operator<<(std::ostream& out, const container& source) {
		std::ostringstream message;
		message << "memory(" << source._data << "|" << source._size << "): ";
		for ( int i = 0; i < source._size; i++) message << i << ":" << source._data[i] << " ";
		out << message.str();
		return out;
	};

private:
	pointer			_data;
	size_type		_size;
};
// Implementation --------------------------------------------------
// Swap ------------------------------------------------------------
template <typename T> void memory<T>::swap( container& source) {
	using std::swap;
	swap(_data, source._data);
	swap(_size, source._size);
};
//Copy assignment
template <class T> typename memory<T>::container& memory<T>::operator=( const container& source) noexcept {
	if (this == &source) return *this;
	container tmp {source};
	swap(tmp);
	return *this;
};
//Move assignment
template <class T> typename memory<T>::container& memory<T>::operator=( container&& source) noexcept {
	container tmp {std::move(source)};
	swap(tmp);
	return *this;
};
#endif

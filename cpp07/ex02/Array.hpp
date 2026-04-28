#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <exception>

template<typename T>
class	Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		Array &operator=(const Array &op);
		~Array();

		T				&operator[](int index);
		const T			&operator[](const int index) const;
		int	size() const;

		class OutOfBoundIndex : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		T				*_elements;
		int	_size;
};

#include "Array.tpp"

#endif

// template <typename T>
// class	Array
// {
// 	public:
// 		class	IndexOutOfBound : public std::exception
// 		{
// 			public:
// 				virtual const char* what() const throw()
// 				{
// 					return "Index out of bound!";
// 				}
// 		};


// 		Array() : _elements(NULL), _size(0) {}

// 		Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

// 		Array(const Array &copy) : _elements(new T[copy._size]), _size(copy._size) 
// 		{
// 			for (int i = 0; i < _size; i++)
// 				_elements[i] = copy._elements[i];
// 		}

// 		Array &operator=(const Array &op)
// 		{
// 			if (this != &op)
// 			{
// 				delete []_elements;
// 				_size = op._size;
// 				_elements = new T[_size];
// 				for (int i = 0; i < _size; i++)
// 					_elements[i] = op._elements[i];
// 			}
// 			return (*this);
// 		}

// 		~Array()
// 		{
// 			delete []_elements;
// 		}


// 		T &operator[](int index)
// 		{
// 			if (index >= _size)
// 				throw IndexOutOfBound();
// 			return _elements[index];
// 		}

// 		const T	&operator[](int index) const
// 		{
// 			if (index >= _size)
// 				throw IndexOutOfBound();
// 			return _elements[index];
// 		}


// 		unsigned int	size() const
// 		{
// 			return _size;
// 		}

// 	private:
// 		T	*_elements;
// 		int	_size;
// };

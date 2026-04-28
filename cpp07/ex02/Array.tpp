#include "Array.hpp"

template<typename T>
Array<T>::Array() : _elements(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

template<typename T>
Array<T>::Array(const Array &copy) : _elements(new T[copy._size]), _size(copy._size)
{
	for (int i = 0; i < _size; i++)
		_elements[i] = copy._elements[i];
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array &op)
{
	if (this != &op)
	{
		delete []_elements;
		this->_size = op._size;
		_elements = new T[_size];
		for (int i = 0; i < _size; i++)
			_elements[i] = op._elements[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete []_elements;
}


template <typename T>
const char* Array<T>::OutOfBoundIndex::what() const throw()
{
	return "Index out of bound!";
}

template <typename T>
T	&Array<T>::operator[](int index)
{
	if (index < 0 || index >= _size)
		throw Array::OutOfBoundIndex();
	return _elements[index];
}

template <typename T>
const T	&Array<T>::operator[](const int index) const
{
	if (index < 0 || index >= _size)
		throw Array::OutOfBoundIndex();
	return _elements[index];
}

template <typename T>
int	Array<T>::size() const
{
	return this->_size;
}

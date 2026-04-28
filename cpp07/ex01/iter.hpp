#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
#include <cstddef>

template <typename T>
void	printElemT(const T &elem)
{
	std::cout << elem << std::endl;
}

template <typename T>
void	doubleValueT(T &x)
{
	x = x * 2;
	// std::cout << x << std::endl;
}


template <typename T, typename Func>
void	iter(T *array, size_t length, Func f)
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

// Overload ?
// template <typename T, typename Func>
// void iter(const T* array, size_t length, Func f) {
// 	for (size_t i = 0; i < length; ++i)
// 		f(array[i]);
// }


#endif

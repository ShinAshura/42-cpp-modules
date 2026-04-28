#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <iterator>
#include <exception>

class	NotFound : public std::exception
{
	public:
		const char* what() const throw()
		{
			return "Value not found in container";
		}
};

template <typename T>
typename T::iterator	easyfind(T &container, int value)
{
	typename T::iterator	itb = container.begin();
	typename T::iterator	ite = container.end();
	typename T::iterator	itFind = std::find(itb, ite, value);

	if (itFind == ite)
		throw NotFound();
		
	return itFind;
}

// Overload for const
template <typename T>
typename T::const_iterator	easyfind(const T &container, int value)
{
	typename T::const_iterator	itb = container.begin();
	typename T::const_iterator	ite = container.end();
	typename T::const_iterator	itFind = std::find(itb, ite, value);

	if (itFind == ite)
		throw NotFound();

	return itFind;
}

// Less verbose veresion but shorter
// template <typename T>
// typename T::iterator	easyfind(T &container, int value)
// {
// 	typename T::iterator	it = std::find(container.begin(), container.end(), value);

// 	if (it == container.end())
// 		throw NotFound();

// 	return it;
// }

#endif

#include <iostream>
#include <string>
#include "iter.hpp"

void print(const int &x)
{
	std::cout << x << std::endl;
}

void doubleVal(int &x)
{
	x = x * 2;
}

int	main()
{
	int	arr[] = {1, 2, 3};
	iter(arr, 3, print);
	iter(arr, 3, doubleVal);
	iter(arr, 3, print);



	std::cout << "\n\n==============================" << std::endl;
	int			tabInt[] = {5, 4, 3, 2, 1};
	std::string	tabStrings[] = {"this", "is", "a", "test"};


	std::cout << "Original int array:" << std::endl;
	iter(tabInt, 5, printElemT<int>);

	std::cout << "\nString array:" << std::endl;
	iter(tabStrings, 4, printElemT<std::string>);

	std::cout << "\nDoubled int array:" << std::endl;
	iter(tabInt, 5, doubleValueT<int>);
	iter(tabInt, 5, printElemT<int>);


	return (0);
}

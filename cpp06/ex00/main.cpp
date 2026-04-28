#include <iostream>
#include <string>
#include "ScalarConverter.hpp"
#include <cstdio>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Please enter a literal." << std::endl 
		<< "Usage : ./convert <literal>" << std::endl;
		return (0);
	}
	std::string	literal = av[1];
	ScalarConverter::convert(literal);

	return (0);
}

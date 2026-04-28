#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <limits>

class	ScalarConverter
{
	public:
		static void	convert(const std::string &literal);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &op);
		~ScalarConverter();
};

#endif

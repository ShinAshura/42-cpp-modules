#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <limits>
#include "ScalarConverter.hpp"
#define	CHAR	1
#define	INT		2
#define	FLOAT	3
#define	DOUBLE	4

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &op)
{
	(void)op;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{

}

int	isChar(std::string literal)
{
	if (literal.length() == 1 && !(std::isdigit(static_cast<unsigned char>(literal[0]))))
		return (1);
	return (0);
}

int isInt(std::string literal)
{
	size_t	i = 0;

	if (literal.empty())
		return 0;
	if ((literal[0] == '+' || literal[0] == '-') && literal.length() > 1)
		i++;
	while (i < literal.length())
	{
		if (!(std::isdigit(static_cast<unsigned char>(literal[i]))))
			return (0);
		i++;
	}
	return (1);
}

int isFloat(const std::string& literal)
{
	size_t	i = 0;
	bool 	dot = false;
	bool	hasDigit = false;

	if (literal.empty() || literal[literal.length() - 1] != 'f')
		return (0);

	if ((literal[0] == '+' || literal[0] == '-') && literal.length() > 1)
		i++;

	while (i < literal.length() - 1)
	{
		if (literal[i] == '.') {
			if (dot)
				return (0);
			dot = true;
		}
		else if (!std::isdigit(static_cast<unsigned char>(literal[i])))
			return (0);
		else
			hasDigit = true;
		i++;
	}
	if (literal[literal.length() - 1] != 'f' || !dot || !hasDigit)
		return (0);
	return (1);
}

int	isDouble(std::string literal)
{
	size_t	i = 0;
	int		dotCount = 0;

	if ((literal[0] == '+' || literal[0] == '-') && literal.length() > 1)
		i++;
	while (i < literal.length())
	{
		if (literal[i] == '.')
			dotCount++;
		else if (!(std::isdigit(static_cast<unsigned char>(literal[i]))) && literal[i] != '.')
			return (0);
		i++;
	}
	if (dotCount == 1)
		return (1);
	return (0);
}

int	getType(std::string literal)
{
	if (isChar(literal))
		return CHAR;
	else if (isInt(literal))
		return INT;
	else if (isFloat(literal))
		return FLOAT;
	else if (isDouble(literal))
		return DOUBLE;
	return (0);
}

void	convertFromChar(std::string literal)
{
	char	c = literal[0];
	std::cout << "char: " << "'" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void convertFromInt(const std::string& literal)
{
	std::istringstream iss(literal);
	long long number;

	if (!(iss >> number) || !iss.eof()) {
		std::cerr << "Invalid integer input" << std::endl;
		return;
	}

	if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min()) {
		std::cerr << "Integer overflow or underflow" << std::endl;
		return;
	}

	int n = static_cast<int>(number);

	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(n))
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	// int output
	std::cout << "int: " << n << std::endl;

	// float & double output
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << std::endl;
}

void convertFromFloat(std::string literal)
{
	if (literal[literal.length() - 1] == 'f')
		literal = literal.substr(0, literal.length() - 1);

	std::istringstream iss(literal);
	float number;

	if (!(iss >> number))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	if (number < 0 || number > 127)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<int>(number)))
		std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(number) << std::endl;

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << number << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(number) << std::endl;
}

void	convertFromDouble(std::string literal)
{
	std::istringstream	iss(literal);
	double	number;

	if (!(iss >> number))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	if (number < 0 || number > 127)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<int>(number)))
		std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(number) << std::endl;

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;
	std::cout << "double: " << number << std::endl;
}

void	ScalarConverter::convert(const std::string &literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
	{
		float f;
		std::istringstream(literal).ignore();
		if (literal == "nanf")
			f = std::numeric_limits<float>::quiet_NaN();
		if (literal == "+inff")
			f = std::numeric_limits<float>::infinity();
		if (literal == "-inff")
			f = -std::numeric_limits<float>::infinity();

		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
		return;
	}

	if (literal == "nan" || literal == "+inf" || literal == "-inf")
	{
		double d;
		if (literal == "nan") 
			d = std::numeric_limits<double>::quiet_NaN();
		if (literal == "+inf")
			d = std::numeric_limits<double>::infinity();
		if (literal == "-inf")
			d = -std::numeric_limits<double>::infinity();

		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return;
	}


	int	type;

	type = getType(literal);

	switch (type)
	{
		case CHAR:
			convertFromChar(literal);
			break;
		case INT:
			convertFromInt(literal);
			break;
		case FLOAT:
			convertFromFloat(literal);
			break;
		case DOUBLE:
			convertFromDouble(literal);
			break;
		default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			break;
	}
}





// int	isFloat(std::string literal)
// {
// 	int 	dot = 0;
// 	int		f = 0;
// 	size_t	i = 0;

// 	if ((literal[0] == '+' || literal[1] == '-') && literal.length() > 1)
// 		i++;
// 	while (i < literal.length())
// 	{
// 		if (literal[i] == 'f' && f == 1)
// 			return (0);
// 		else if (literal[i] == '.' && dot == 1)
// 			return (0);
// 		else if (literal[i] == 'f' && i == literal.length() - 1)
// 			f = 1;
// 		else if (literal[i] == '.' && i != literal.length() - 1)
// 			dot = 1;
// 		else if (!(std::isdigit(static_cast<unsigned char>(literal[i]))) && (literal[i] != '.' && literal[i] != 'f'))
// 			return (0);
// 		i++;
// 	}
// 	if (f == 1 && dot == 1)
// 		return (1);
// 	return (0);
// }




// void	convertFromInt(std::string literal)
// {
// 	long long	number = 0;
// 	int			negative = 0;
// 	size_t	i = 0;

// 	if (literal[i] == '+' || literal[i] == '-')
// 		i++;
// 	if (literal[0] == '-')
// 		negative = 1;
// 	while (literal[i])
// 	{
// 		number = (number * 10) + (literal[i] - 48);
// 		i++;
// 	}
// 	if (number > __INT_MAX__)
// 	{
// 		std::cerr << "Overflow INT MAX, please input a reasonable number" << std::endl;
// 		return;
// 	}
// 	if (number < -2147483648)
// 	{
// 		std::cerr << "Underflow INT MIN, please input a reasonable number" << std::endl;
// 		return;
// 	}
// 	if (negative == 1)
// 		number = -number;

// 	if (number >= 32 && number <= 126)
// 		std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
// 	else
// 		std::cout << "char: Non displayable" << std::endl;
// 	std::cout << "int: " << number << std::endl;
// 	std::cout << std::fixed << std::setprecision(1);
// 	std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;
// 	std::cout << "double: " << static_cast<double>(number) << std::endl;
// }




// void	convertFromFloat(std::string literal)
// {
// 	float	number = 0;
// 	float	fractional = 0;
// 	float	precision = 1;
// 	int		negative = 0;
// 	size_t	i = 0;

// 	if (literal[i] == '+' || literal[i] == '-')
// 		i++;
// 	if (literal[0] == '-')
// 		negative = 1;
// 	while (literal[i] != '.')
// 	{
// 		number = (number * 10) + (literal[i] - 48);
// 		i++;
// 	}
// 	i++;
// 	while (literal[i] && literal[i] != 'f')
// 	{
// 		precision = fractional / 10;
// 		fractional = fractional + ((literal[i] - 48) * precision);
// 		i++;
// 	}
// 	if (negative == 1)
// 		number = -(number + fractional);
// 	else
// 		number = (number + fractional);

// 	if (number >= 32 && number <= 126)
// 		std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
// 	else
// 		std::cout << "char: Non displayable" << std::endl;
// 	std::cout << "int: " << static_cast<int>(number) << std::endl;
// 	std::cout << std::fixed << std::setprecision(1);
// 	std::cout << "float: " << (number) << "f" << std::endl;
// 	std::cout << "double: " << static_cast<double>(number) << std::endl;
// }

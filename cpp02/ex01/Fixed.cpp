#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed &op)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &op)
		this->_value = op.getRawBits();
		// this->_value = op._value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = integer << _fractional_bits;
}

Fixed::Fixed(const float ft_number)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = static_cast<int>(roundf(ft_number * (1 << _fractional_bits)));
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(this->_value) / (1 << _fractional_bits));
}

int	Fixed::toInt() const
{
	return (this->_value >> _fractional_bits);
}

int	Fixed::getRawBits() const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

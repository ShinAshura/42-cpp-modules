#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;

Fixed::Fixed()
{
	this->_fpvalue = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
	this->_fpvalue = copy.getRawBits();
}

Fixed	&Fixed::operator=(const Fixed &op)
{
	if (this != &op)
		this->_fpvalue = op.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{

}

Fixed::Fixed(const int integer)
{
	this->_fpvalue = integer << _fractional_bits;
}

Fixed::Fixed(const float ft_number)
{
	this->_fpvalue = static_cast<int>(roundf(ft_number * (1 << _fractional_bits)));
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(this->_fpvalue / (1 << _fractional_bits)));
}

int	Fixed::toInt() const
{
	return (static_cast<int>(this->_fpvalue >>_fractional_bits));
}

int	Fixed::getRawBits() const
{
	return (this->_fpvalue);
}

void	Fixed::setRawBits(const int raw)
{
	this->_fpvalue = raw;
}

// ------------------------------------------------------------------

bool	Fixed::operator>(const Fixed &op) const
{
	return (this->_fpvalue > op._fpvalue);
}

bool	Fixed::operator<(const Fixed &op) const
{
	return (this->_fpvalue < op._fpvalue);
}

bool	Fixed::operator>=(const Fixed &op) const
{
	return (this->_fpvalue >= op._fpvalue);
}

bool	Fixed::operator<=(const Fixed &op) const
{
	return (this->_fpvalue <= op._fpvalue);
}

bool	Fixed::operator==(const Fixed &op) const
{
	return (this->_fpvalue == op._fpvalue);
}

bool	Fixed::operator!=(const Fixed &op) const
{
	return (this->_fpvalue != op._fpvalue);
}

Fixed	Fixed::operator-(const Fixed &op) const
{
	Fixed	result;

	result.setRawBits(this->_fpvalue - op._fpvalue);
	return (result);
}

Fixed	Fixed::operator+(const Fixed &op) const
{
	Fixed	result;

	result.setRawBits(this->_fpvalue + op._fpvalue);
	return (result);
}

Fixed	Fixed::operator*(const Fixed &op) const
{
	Fixed		result;

	long long	lhs = static_cast<long long>(this->_fpvalue);
	long long	rhs = static_cast<long long>(op._fpvalue);
	result.setRawBits(static_cast<int>((lhs * rhs) >> _fractional_bits));
	
	return (result);
}

Fixed	Fixed::operator/(const Fixed &op) const
{
	if (op._fpvalue == 0)
	{
		std::cerr << "Error: cannot divide by zero" << std::endl;
		return (Fixed(0));
	}

	Fixed	result;

	long long	lhs = static_cast<long long>(this->_fpvalue) << _fractional_bits;
	long long	rhs = static_cast<long long>(op._fpvalue);
	result.setRawBits(static_cast<int>(lhs / rhs));

	return (result);
}

// prefix increment
Fixed	&Fixed::operator++()
{
	++this->_fpvalue;
	return (*this);
}

// postfix increment
Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;

	this->_fpvalue++;
	return (temp);
}

// prefix decrement
Fixed	&Fixed::operator--()
{
	--this->_fpvalue;
	return (*this);
}

// postfix decrement
Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;

	this->_fpvalue--;
	return (temp);
}


Fixed	&Fixed::min(Fixed &fpn1, Fixed &fpn2)
{
	return (fpn1 < fpn2 ? fpn1 : fpn2);
}

const Fixed	&Fixed::min(const Fixed &fpn1, const Fixed &fpn2)
{
	return (fpn1 < fpn2 ? fpn1 : fpn2);
}

Fixed	&Fixed::max(Fixed &fpn1, Fixed &fpn2)
{
	return (fpn1 > fpn2 ? fpn1 : fpn2);
}

const Fixed	&Fixed::max(const Fixed &fpn1, const Fixed &fpn2)
{
	return (fpn1 > fpn2 ? fpn1 : fpn2);
}




std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

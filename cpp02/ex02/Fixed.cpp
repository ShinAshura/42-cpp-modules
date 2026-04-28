#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;

Fixed::Fixed()
{
	this->_fixed_integer_value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
	// this->_fixed_integer_value = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &op)
{
	if (this != &op)
		this->_fixed_integer_value = op.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{

}

// --------------------------------------------------------------------------

Fixed::Fixed(const int integer)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixed_integer_value = integer << _fractional_bits;
}

Fixed::Fixed(const float ft_number)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixed_integer_value = static_cast<int>(roundf(ft_number * (1 << _fractional_bits)));
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(this->_fixed_integer_value) / (1 << _fractional_bits));
}

int	Fixed::toInt() const
{
	return (this->_fixed_integer_value >> _fractional_bits);
}

int	Fixed::getRawBits() const
{
	return (this->_fixed_integer_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->_fixed_integer_value = raw;
}

// ------------------------------------------------------------------

bool	Fixed::operator>(const Fixed &op) const
{
	return (this->_fixed_integer_value > op._fixed_integer_value);
	// return (this->getRawBits() > op.getRawBits());
}

bool	Fixed::operator<(const Fixed &op) const
{
	return (this->getRawBits() < op.getRawBits());
}

bool	Fixed::operator>=(const Fixed &op) const
{
	return (this->_fixed_integer_value >= op._fixed_integer_value);
}

bool	Fixed::operator<=(const Fixed &op) const
{
	return (this->_fixed_integer_value <= op._fixed_integer_value);
}

bool	Fixed::operator==(const Fixed &op) const
{
	return (this->getRawBits() == op.getRawBits());
}

bool	Fixed::operator!=(const Fixed &op) const
{
	return (this->_fixed_integer_value != op._fixed_integer_value);
}

Fixed	Fixed::operator+(const Fixed &op) const
{
	Fixed	result;

	result.setRawBits(this->_fixed_integer_value + op._fixed_integer_value);
	return (result);
}

Fixed	Fixed::operator-(const Fixed &op) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - op.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed &op) const
{
	Fixed		result;

	long long	left = static_cast<long long>(this->_fixed_integer_value);
	long long	right = static_cast<long long>(op._fixed_integer_value);
	result.setRawBits(static_cast<int>((left * right) >> _fractional_bits));
	return (result);
}
// result.setRawBits((this->getRawBits() * op.getRawBits()) >> _fractional_bits);

Fixed	Fixed::operator/(const Fixed &op) const
{
	if (op._fixed_integer_value == 0)
	{
		std::cerr << "Error: Cannot divide by zero" << std::endl;
		return (Fixed(0));
	}

	Fixed		result;
	long long	left = static_cast<long long>(this->_fixed_integer_value) << _fractional_bits;
	long long	right = static_cast<long long>(op._fixed_integer_value);
	result._fixed_integer_value = static_cast<int>(left / right);
	return (result);
}
// result._fixed_integer_value = (this->_fixed_integer_value / op._fixed_integer_value) >> _fractional_bits;

// prefix increment
Fixed	&Fixed::operator++()
{
	++this->_fixed_integer_value;
	return (*this);
}

// postfix increment
Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	// temp._fixed_integer_value++; // false
	this->_fixed_integer_value++;
	return (temp);
}

// prefix decrement
Fixed	&Fixed::operator--()
{
	--this->_fixed_integer_value;
	return (*this);
}

//postfix decrement
Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;

	// temp._fixed_integer_value--; // false
	this->_fixed_integer_value--;
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



std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
    return (out);
}




/* Fixed	&Fixed::min(Fixed &fpn1, Fixed &fpn2)
{
	if (fpn1 < fpn2)
		return (fpn1);
	return (fpn2);
}

const Fixed &Fixed::min(const Fixed &fpn1, const Fixed &fpn2)
{
	if (fpn1 < fpn2)
		return (fpn1);
	return (fpn2);
}

Fixed	&Fixed::max(Fixed &fpn1, Fixed &fpn2)
{
	if (fpn1 > fpn2)
		return (fpn1);
	return (fpn2);
}

const Fixed	&Fixed::max(const Fixed &fpn1, const Fixed &fpn2)
{
	if (fpn1 > fpn2)
		return (fpn1);
	return (fpn2);
} */

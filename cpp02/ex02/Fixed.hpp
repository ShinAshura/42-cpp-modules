#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &op);
		~Fixed();

		Fixed(const int	integer);
		Fixed(const float ft_number);

		float	toFloat() const;
		int		toInt() const;

		bool	operator>(const Fixed &op) const;
		bool	operator<(const Fixed &op) const;
		bool	operator>=(const Fixed &op) const;
		bool	operator<=(const Fixed &op) const;
		bool	operator==(const Fixed &op) const;
		bool	operator!=(const Fixed &op) const;

		Fixed	operator+(const Fixed &op) const;
		Fixed	operator-(const Fixed &op) const;
		Fixed	operator*(const Fixed &op) const;
		Fixed	operator/(const Fixed &op) const;

		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		static Fixed	&min(Fixed &fpn1, Fixed &fpn2);
		static const Fixed	&min(const Fixed &fpn1, const Fixed &fpn2);
		static Fixed	&max(Fixed &fpn1, Fixed &fpn2);
		static const Fixed	&max(const Fixed &fpn1, const Fixed &fpn2);

		int		getRawBits() const;
		void	setRawBits(const int raw);

	private:
		int					_fixed_integer_value;
		static const int	_fractional_bits;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif

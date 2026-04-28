#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed &operator=(const Fixed& op);
		~Fixed();
		Fixed(const int	integer);
		Fixed(const float ft_number);

		float	toFloat() const;
		int		toInt() const;
		int		getRawBits() const;
		void	setRawBits(int const raw);
		
	private:
		int					_value;
		static const int	_fractional_bits;	
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
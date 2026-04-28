#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& cpy);			// copy (Default) constructor
		Fixed &operator=(const Fixed& op);	// copy assignment operator overload
		~Fixed();
		int		getRawBits() const;
		void	setRawBits(int const raw);

	private:
		int					_value;
		static const int	_fractional_bits;
};

#endif

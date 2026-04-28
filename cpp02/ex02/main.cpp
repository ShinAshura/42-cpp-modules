#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;


	std::cout << "=====================================" << std::endl;


	Fixed c(Fixed(5.05f) * Fixed(2));

	std::cout << Fixed::min(a , b) << std::endl;

	std::cout << c << std::endl;
	std::cout << --c << std::endl;
	// std::cout << ++c << std::endl;
	std::cout << c++ << std::endl;
	std::cout << c << std::endl;
	std::cout << c * 2 << std::endl;
	std::cout << c / 2 << std::endl;
	std::cout << c + 5 << std::endl;
	std::cout << c - 5 << std::endl;

	Fixed	d = c * 2;
	std::cout << std::endl << d / 2 << std::endl;
	std::cout << std::endl << d / 0 << std::endl;


	std::cout << "=====================================" << std::endl;

	Fixed	test1(10);
	Fixed	test2(20);
	Fixed	&smaller = Fixed::min(test1, test2);
	std::cout << smaller << std::endl;
	smaller = Fixed(5);
	std::cout << smaller << std::endl;


	std::cout << "=====================================" << std::endl;

	const Fixed	test3(10);
	const Fixed	test4(20);
	const Fixed	&smaller2 = Fixed::min(test1, test2);
	std::cout << smaller2 << std::endl;
	// smaller2 = Fixed(5);  // does not work on compilation since it's const
	std::cout << smaller2 << std::endl;



	std::cout << "=====================================" << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "c : " << c << std::endl;
	std::cout << "== " << (b == c) << std::endl;
	std::cout << "<  " << (a < c) << std::endl;
	std::cout << ">  " << (a > c) << std::endl;
	std::cout << "!= " << (a != c) << std::endl;

	return 0;
}

#include <iostream>
#include "whatever.hpp"

int	main( void ) {

	{
		std::cout << "===== 42 main =====" << std::endl;
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	{
		std::cout << "\n===== other test =====" << std::endl;
		std::cout << max<int>(2, 4) << std::endl;
		std::cout << max<double>(22.4, 47.4) << std::endl;
		std::cout << max<char>('a', 'z') << std::endl;

		std::cout << min<int>(78, 23) << std::endl;
		std::cout << min<double>(78.4, 23.4) << std::endl;
		std::cout << min<char>('a', 'z') << std::endl;

		int	a = 12;
		int	b = 99;

		std::cout << "a : " << a << ", b : " << b << std::endl;
		swap(a, b);
		std::cout << "a : " << a << ", b : " << b << std::endl;
	}

	return 0;
}


#include <iostream>
#include <string>

int	main()
{
	std::string		var = "HI THIS IS BRAIN";
	std::string*	stringPTR = &var;
	std::string&	stringREF = var;

	std::cout << &var << std::endl
			  << stringPTR << std::endl
			  << &stringREF << std::endl;

	std::cout << var << std::endl
			  << *stringPTR << std::endl
			  << stringREF << std::endl;

	return (0);
}

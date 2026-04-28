#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Please use it this way : ./RPN <inverted Polish mathematical expression>" << std::endl;
		return 1;
	}

	if (RPN::isValidArg(av[1]) == false)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	
	RPN::calculate(av[1]);

	return 0;
}


// $> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
// 42
// $> ./RPN "7 7 * 7 -"
// 42
// $> ./RPN "1 2 * 2 / 2 * 2 4 - +"
// 0
// $> ./RPN "(1 + 1)"
// Error

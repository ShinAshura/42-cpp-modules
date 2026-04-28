#include <iostream>
#include <string>
#include "Harl.hpp"

// int	getLevelIndex(std::string level)
// {
// 	if (level == "DEBUG")
// 		return (0);
// 	if (level == "INFO")
// 		return (1);
// 	if (level == "WARNING")
// 		return (2);
// 	if (level == "ERROR")
// 		return (3);
// 	return (-1);
// }

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Please give one and only one level of complaint" << 		std::endl
				  << "Usage : ./harlFilter <level>" << std::endl;
		return (1);
	}
	
	Harl	harl;

	harl.complain(av[1]);
	return (0);
}

// switch (getLevelIndex(level))
// {
// 	case 0 :
// 		harl.complain("DEBUG");
// 		break;
// 	case 1 :
// 		harl.complain("INFO");
// 		break;
// 	case 2 :
// 		harl.complain("WARNING");
// 		break;
// 	case 3 :
// 		harl.complain("ERROR");
// 		break;
// 	default :
// 		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
// }

#include <iostream>
#include <string>
#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	typedef	void (Harl::*harlFuncPtr)();
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	harlFuncPtr	functions[] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	int	i = 0;
	while (i < 4)
	{
		if (level == levels[i])
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			std::cout << "[ " << levels[i] << " ]" << std::endl;
			(this->*functions[i++])();
			std::cout << std::endl;
		case 1:
			std::cout << "[ " << levels[i] << " ]" << std::endl;
			(this->*functions[i++])();
			std::cout << std::endl;
		case 2:
			std::cout << "[ " << levels[i] << " ]" << std::endl;
			(this->*functions[i++])();
			std::cout << std::endl;
		case 3:
			std::cout << "[ " << levels[i] << " ]" << std::endl;
			(this->*functions[i])();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

void	Harl::_debug()
{
	std::cout << DEBUG << std::endl;
}

void	Harl::_info()
{
	std::cout << INFO << std::endl;
}

void	Harl::_warning()
{
	std::cout << WARNING << std::endl;
}

void	Harl::_error()
{
	std::cout << ERROR << std::endl;
}




/* void	Harl::complain(std::string level)
{
	// typedef void (Harl::*harlFunctionPtr)();
	// harlFunctionPtr functions[] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	i = 0;
	while (i < 4)
	{
		if (level == levels[i])
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			std::cout << "[ " << levels[i] << " ]" << std::endl;
			_debug();
			std::cout << std::endl;
			_info();
			std::cout << std::endl;
			_warning();
			std::cout << std::endl;
			_error();
			std::cout << std::endl;
			break;
		case 1:
			std::cout << "[ " << levels[i] << " ]" << std::endl;
			_info();
			std::cout << std::endl;
			_warning();
			std::cout << std::endl;
			_error();
			std::cout << std::endl;
			break;
		case 2:
			std::cout << "[ " << levels[i] << " ]" << std::endl;
			_warning();
			std::cout << std::endl;
			_error();
			std::cout << std::endl;
			break;
		case 3:
			std::cout << "[ " << levels[i] << " ]" << std::endl;
			_error();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
} */

// switch (i)
// 	{
// 		case 0:
// 			for (int i = 0; i < 4; i++)
// 			{
// 				std::cout << "[ " << levels[i] << " ]" << std::endl;
// 				(this->*functions[i])();
// 				std::cout << std::endl;
// 			}
// 			break;
// 		case 1:
// 			for (int i = 1; i < 4; i++)
// 			{
// 				std::cout << "[ " << levels[i] << " ]" << std::endl;
// 				(this->*functions[i])();
// 				std::cout << std::endl;
// 			}
// 			break;
// 		case 2:
// 			for (int i = 2; i < 4; i++)
// 			{
// 				std::cout << "[ " << levels[i] << " ]" << std::endl;
// 				(this->*functions[i])();
// 				std::cout << std::endl;
// 			}
// 			break;
// 		case 3:
// 			std::cout << "[ " << levels[i] << " ]" << std::endl;
// 			(this->*functions[i])();
// 			std::cout << std::endl;
// 			break;
// 		default:
// 			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
// 			break;
// 	}


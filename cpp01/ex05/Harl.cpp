#include <iostream>
#include <string>
#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	typedef	void (Harl::*harlFuncPtr)();
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	harlFuncPtr	functions[] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << "No level of complain : " << level <<  std::endl;
}
// if (level == "debug" || level == "DEBUG")
// 	debug();
// if (level == "info" || level == "INFO")
// 	info();
// if (level == "warning" || level == "WARNING")
// 	warning();
// if (level == "error" || level == "ERROR")
// 	error();

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

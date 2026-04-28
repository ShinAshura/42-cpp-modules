#include <iostream>
#include "Contact.class.hpp"

Contact::Contact(void)
{
	// std::cout << "Constructor called" << '\n';
	// return;
}

Contact::~Contact(void)
{
	// std::cout << "C Destructor called" << '\n';
	// return;
}

int	Contact::isValidNumber(std::string number)
{
	for (int i = 0; number[i]; i++)
		if (!isdigit(number[i]))
			return (0);
	return (1);
}

void Contact::add() {
	std::cout << std::endl << "Type the first name: ";
	if(!std::getline(std::cin >> std::ws, _first_name))
		return;
	std::cout << "Type the last name: ";
	if (!std::getline(std::cin >> std::ws, _last_name))
		return;
	std::cout << "Type the nickname: ";
	if (!std::getline(std::cin >> std::ws, _nickname))
		return;
	while (true)
	{
		std::cout << "Type the phone number: ";
		if (!std::getline(std::cin >> std::ws, _phone_number))
			return;
		if (isValidNumber(_phone_number))
			break;
		std::cout << "Invalid phone number. Please use digits only." << std::endl;
	}
	std::cout << "Type the darkest secret: ";
	if (!std::getline(std::cin >> std::ws, _darkest_secret))
		return;
}


std::string	formatSearch(std::string& str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

// void	Contact::getContact(int index)
// {
// 	std::cout << "     INDEX|FIRST_NAME| LAST_NAME|  NICKNAME|" << std::endl;
// 	std::cout << "         " << index;
// 	std::cout << "|";
// 	std::cout << std::right << std::setw(10) << std::setfill(' ') << formatSearch(_first_name);
// 	std::cout << "|";
// 	std::cout << std::right << std::setw(10) << std::setfill(' ') << formatSearch(last_name);
// 	std::cout << "|";
// 	std::cout << std::right << std::setw(10) << std::setfill(' ') << formatSearch(nickname) << "|" << std::endl;
// }

void Contact::searchContact(int index)
{
	std::cout << std::setw(10) << index + 1 << "|"
	          << std::setw(10) << formatSearch(_first_name) << "|"
	          << std::setw(10) << formatSearch(_last_name) << "|"
	          << std::setw(10) << formatSearch(_nickname) << "|"
			  << std::endl;
}

void Contact::getContact(int index)
{
	std::cout << std::endl
			  << "index          : " << index << std::endl
	          << "first name     : " << _first_name << std::endl
	          << "last name      : " << _last_name << std::endl
	          << "nickname       : " << _nickname << std::endl
			  << "phone number   : " << _phone_number << std::endl
	          << "darkest secret : " << _darkest_secret << std::endl;
}
// void Contact::getContact(int index)
// {
// 	std::cout << std::endl
// 			  << "index          : " << index << std::endl
// 	          << "first name     : " << formatSearch(_first_name) << std::endl
// 	          << "last name      : " << formatSearch(_last_name) << std::endl
// 	          << "nickname       : " << formatSearch(_nickname) << std::endl
// 			  << "phone number   : " << formatSearch(_phone_number) << std::endl
// 	          << "darkest secret : " << formatSearch(_darkest_secret) << std::endl;
// }

int		Contact::isEmpty()
{
	if (_first_name.empty() || _last_name.empty() || _nickname.empty() || _phone_number.empty() || _darkest_secret.empty())
		return (1);
	return (0);
}

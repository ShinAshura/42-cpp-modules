#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
// #include <cstring>
// #include <string>
#include <cstdlib>
#include <iostream>

int	main()
{
	std::string	user_input;
	PhoneBook	phonebook;
	Contact		contact;

	while (user_input != "EXIT")
	{
		if (std::cin.eof())
		{
			std::cout << "\nInput closed (EOF detected). Exiting..." << std::endl;
			return (1);
		}
		std::cout << "\nPlease use one of those 3 commands : ADD | SEARCH | EXIT" << std::endl;
		if (!(std::cin >> user_input))
		{
			std::cout << "\nInput closed (EOF detected). Exiting..." << std::endl;
			return (1);
		}
		if (user_input == "ADD")
		{
			contact.add();
			phonebook.addContact(contact);
		}
		if (user_input == "SEARCH")
		{
			std::string	index_input;

			phonebook.search();
			std::cout << "Enter an index : ";
			if (!(std::cin >> index_input))
			{
				std::cout << "\nInput closed (EOF detected). Exiting..." << std::endl;
				return (1);
			}
			if (index_input.length() != 1 || !isdigit(index_input[0]))
			{
				std::cout <<  "Invalid index" << std::endl;
				continue;
			}
			phonebook.searchIndex(atoi(index_input.c_str()));
		}
	}
	std::cout << "Quitting... Contacts are gone FOREVER!" << std::endl;
	return (0);
}

#include <iostream>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) : _contact_count(0)
{
	// std::cout << "Constructor called" << std::endl;
	// return;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << " PB Destructor called" << std::endl;
	// return;
}

// void	PhoneBook::addContact(const Contact& newContact)
// {
// 	if (_contact_index < 8)
// 	{
// 		_contacts[_contact_index] = newContact;
// 		_contact_count++;
// 		_contact_index++;
// 	}
// 	else
// 	{
// 		_contact_index = 0;
// 		_contacts[_contact_index] = newContact;
// 		_contact_index++;
// 	}
// }

void PhoneBook::addContact(const Contact& newContact) {
	_contacts[_contact_count % 8] = newContact;
	_contact_count++;
}

void	PhoneBook::search()
{
	std::cout << std::endl << "     INDEX|FIRST_NAME| LAST_NAME|  NICKNAME|" << std::endl;
	for (int i = 0; i < 8; i++)
		if (!_contacts[i].isEmpty())
			_contacts[i].searchContact(i);
	std::cout << std::endl;
}

void	PhoneBook::searchIndex(int index)
{
	if (index < 1 || index > 8)
	{
		std::cout <<  "Invalid index" << std::endl;
		return;
	}
	if (_contacts[index - 1].isEmpty())
	{
		std::cout << "No contact on this index" << std::endl;
		return;
	}
	_contacts[index - 1].getContact(index);
}

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
#include "Contact.class.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(const Contact& newContact);
		void	search(void);
		void	searchIndex(int index);

	private:
		Contact	_contacts[8];
		int		_contact_count;
		// int		_contact_index;

};

#endif

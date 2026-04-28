#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
#include <string>
#include <iomanip>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		void	add(void);
		int		isValidNumber(std::string number);
		void	searchContact(int index);
		void	getContact(int index);
		int		isEmpty(void);

	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;

};

#endif
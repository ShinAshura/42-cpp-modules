#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>
#include <string>

class	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal &operator=(const WrongAnimal &op);
		virtual ~WrongAnimal();

		std::string	getType() const;
		void		makeSound() const;

	protected:
		std::string	_type;
};

#endif

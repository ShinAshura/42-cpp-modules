#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

class	Animal
{
	public:
		Animal();
		Animal(const Animal &copy);
		Animal &operator=(const Animal &op);
		virtual ~Animal();

		virtual void		makeSound() const;
		virtual std::string	getType() const;

	protected:
		std::string _type;
};

#endif

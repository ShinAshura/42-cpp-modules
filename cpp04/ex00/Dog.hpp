#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include <string>
#include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &op);
		virtual ~Dog();

		virtual void		makeSound() const;
		virtual std::string	getType() const;
};

#endif

#include <iostream>
#include <string>
#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure() : AMateria()
{
	// std::cout << "Cure Constructor called" << std::endl;
	this->_type = "cure";
}

Cure::Cure(const Cure &copy) : AMateria(copy._type)
{
	// std::cout << "Cure Copy constructor called" << std::endl;
	this->_type = copy._type;
}

Cure	&Cure::operator=(const Cure &op)
{
	if (this != &op)
	{
		// std::cout << "Cure Copy assignment operator overload called" << std::endl;
		AMateria::operator=(op);
	}
	return (*this);
}

Cure::~Cure()
{
	// std::cout << "Cure Destructor called" << std::endl;
}

AMateria*	Cure::clone() const
{
	// AMateria*	newCureMateria;

	// newCureMateria = new Cure();
	// return (newCureMateria);
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << "Cure: * heals " << target.getName() << "'s wounds *" << std::endl;
}

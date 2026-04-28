#include <iostream>
#include <string>
#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice contructor called" << std::endl;
	// this->_type = "ice";
}

Ice::Ice(const Ice &copy) : AMateria()
{
	// std::cout << "Ice copy constructor called" << std::endl;
	this->_type = copy._type;
}

Ice	&Ice::operator=(const Ice &op)
{
	if (this != &op)
	{
		// std::cout << "Ice copy assignement operator overload called" << std::endl;
		AMateria::operator=(op);
		// this->_type = op._type;
	}
	return (*this);
}

Ice::~Ice()
{
	// std::cout << "Ice Destructor called" << std::endl;
}

AMateria*	Ice::clone() const
{
	// AMateria	*newIceMateria;

	// newIceMateria = new Ice();
	// return (newIceMateria);
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "Ice: * shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

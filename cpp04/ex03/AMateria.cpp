#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("AMateria_default")
{
	// std::cout << "AMateria Constructor called" << std::endl;
	// this->_type = "AMateria_default";
	return;
}

AMateria::AMateria(const std::string &type) : _type(type)
{
	// std::cout << "AMateria Constructor called" << std::endl;
	// this->_type = type;
}

AMateria::AMateria(const AMateria &copy) : _type(copy._type)
{
	// std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &op)
{
	if (this != &op)
	{
		// this->_type = op._type; // not to be copied
		// std::cout << "AMateria copy assignment operator overload called" << std::endl;
	}
	return (*this);
}

AMateria::~AMateria()
{
	// std::cout << "AMateria Destructor called" << std::endl;
}

const std::string	&AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* uses base AMateria on " << target.getName() << " *" << std::endl;
}

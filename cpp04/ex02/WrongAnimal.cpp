#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Default_WrongAnimal_Type")
{
	std::cout << "WrongAnimal Constructor called" << std::endl;
	return;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : _type(copy._type)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	return;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &op)
{
	if (this != &op)
	{
		this->_type = op._type;
		std::cout << "WrongAnimal Copy assignement operator overload called" << std::endl;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes a sound" << std::endl;
}

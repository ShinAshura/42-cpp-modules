#include <iostream>
#include <string>
#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Default_Animal_type")
{
	std::cout << "Animal Constructor called" << std::endl;
	return;
}

AAnimal::AAnimal(const AAnimal &copy) : _type(copy._type)
{
	std::cout << "Animal Copy constructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &op)
{
	if (this != &op)
	{
		this->_type = op._type;
		std::cout << "Animal Copy assignment operator overload called" << std::endl;
	}
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

void	AAnimal::makeSound() const
{
	std::cout << "Animal makes a sound" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (this->_type);
}

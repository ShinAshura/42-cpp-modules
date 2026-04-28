#include <iostream>
#include <string>
#include "Animal.hpp"

Animal::Animal() : _type("Default_Animal_type")
{
	std::cout << "Animal Constructor called" << std::endl;
	return;
}

Animal::Animal(const Animal &copy) : _type(copy._type)
{
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal &op)
{
	if (this != &op)
	{
		this->_type = op._type;
		std::cout << "Animal Copy assignment operator overload called" << std::endl;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal makes a sound" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->_type);
}

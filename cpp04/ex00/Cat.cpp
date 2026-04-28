#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat Constructor called" << std::endl;
	this->_type = "Cat";
	return;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	_type = copy._type;
}

Cat	&Cat::operator=(const Cat &op)
{
	if (this != &op)
	{
		this->_type = op._type;
		// Animal::operator=(op); ?????
		std::cout << "Cat Copy assignment operator called" << std::endl;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

std::string	Cat::getType() const
{
	return (this->_type);
}

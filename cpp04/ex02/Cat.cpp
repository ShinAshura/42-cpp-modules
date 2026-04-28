#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : AAnimal()
{
	std::cout << "Cat Constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	return;
}

Cat::Cat(const Cat &copy) : AAnimal(copy)
{
	this->_brain = new Brain(*copy._brain);
	std::cout << "Cat Copy constructor called" << std::endl;
}
// _type = copy._type; // redundant, not necessary

Cat	&Cat::operator=(const Cat &op)
{
	if (this != &op)
	{
		AAnimal::operator=(op);
		delete this->_brain;
		this->_brain = new Brain(*op._brain);
		std::cout << "Cat Copy assignment operator called" << std::endl;
	}
	return (*this);
}

Cat::~Cat()
{
	delete this->_brain;
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

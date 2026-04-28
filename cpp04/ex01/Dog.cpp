#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	return;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	// _brain = copy._brain; // shallow copy
	this->_brain = new Brain(*copy._brain); // Deep Purple copy (as it will have its own copy, + won't double free / segfault
	return;
}
// this->_type = copy._type;  // redundant, not necessary

Dog	&Dog::operator=(const Dog &op)
{
	if (this != &op)
	{
		Animal::operator=(op);
		delete this->_brain;
		this->_brain = new Brain(*op._brain);
		std::cout << "Dog Copy assignment operator overload called" << std::endl;
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog Destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

std::string	Dog::getType() const
{
	return (this->_type);
}

void	Dog::setIdea(int index, const std::string idea)
{
	_brain->setIdea(index, idea);
}

std::string	Dog::getIdea(int index)
{
	return (_brain->getIdea(index));
}

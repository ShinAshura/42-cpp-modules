#include <iostream>
#include <string>
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat Constructor called" << std::endl;
	this->_type = "WrongCat";
	return;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	this->_type = copy._type;
	std::cout << "WrongCat Copy contructor called" << std::endl;
	return;
}

WrongCat	&WrongCat::operator=(const WrongCat &op)
{
	if (this != &op)
	{
		this->_type = op._type;
		std::cout << "WrongCat Copy assignment operator called" << std::endl;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

std::string	WrongCat::getType() const
{
	return (this->_type);
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
	return;
}

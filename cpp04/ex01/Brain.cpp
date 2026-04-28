#include <iostream>
#include <string>
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor called" << std::endl;
	return;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
}

Brain	&Brain::operator=(const Brain &op)
{
	if (this != &op)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = op._ideas[i];
		std::cout << "Brain copy assignment operator overload called" << std::endl;
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

void	Brain::setIdea(int index, const std::string idea)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (this->_ideas[index]);
	return "";
}

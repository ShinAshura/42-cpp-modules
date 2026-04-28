#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie" << this->_name << " created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " died" << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

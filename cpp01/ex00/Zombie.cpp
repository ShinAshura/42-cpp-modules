#include <string>
#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	// announce();
}

Zombie::~Zombie(void)
{
	std::cout << _name << " died" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


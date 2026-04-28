#include <iostream>
#include <string>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weaponA(weapon)
{

}

HumanA::~HumanA()
{

}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weaponA.getType() << std::endl;
}

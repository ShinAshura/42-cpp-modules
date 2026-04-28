#include <iostream>
#include <string>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weaponB(NULL)
{

}

HumanB::~HumanB()
{

}

void	HumanB::attack()
{
	if (this->_weaponB)
		std::cout << this->_name << " attacks with their weapon " << this->_weaponB->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with their dirty hands" << std::endl;
}

void	HumanB::setWeapon(Weapon& type)
{
	this->_weaponB = &type;
}

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "Default constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : 
	_name(copy._name),
	_hit_point(copy._hit_point),
	_energy_point(copy._energy_point),
	_attack_damage(copy._attack_damage)
{
	std::cout << "ClapTrap Copy constructor called for " << this->_name << std::endl;
	return;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &op)
{
	if (this != &op)
	{
		this->_name = op._name;
		this->_hit_point = op._hit_point;
		this->_energy_point = op._energy_point;
		this->_attack_damage = op._attack_damage;
		std::cout << "ClapTrap Copy assignment operator overload called for " << this->_name << std::endl;
	}
	return (*this);
}
// *this = op; // incorect and dangerous ? not to be used ?

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for " << this->_name << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_hit_point <= 0 || _energy_point <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no more hit points or energy points to attack!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_point = this->_energy_point - 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hit_point = this->_hit_point - amount;
	std::cout << "ClapTrap " << this->_name << " has taken " << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_point <= 0 || _energy_point <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no more hit points or energy points to repair!" << std::endl;
		return;
	}
	this->_hit_point = this->_hit_point + amount;
	this->_energy_point = this->_energy_point - 1;
	std::cout << "ClapTrap " << this->_name << " has repaired itself by " << amount << " points!" << std::endl;
}

// std::cout << "[HP: " << _hit_point << "] [EP: " << _energy_point << "]" << std::endl;

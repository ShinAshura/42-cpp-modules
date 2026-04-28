#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

// ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
// //: _name(name) ?
// {
// 	std::cout << "ScavTrap constructor1 called" << std::endl;
// 	_name = name;
// 	_hit_point = 100;
// 	_energy_point = 50;
// 	_attack_damage = 20;
// 	return;
// }

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
//: _name(name) ?
{
	std::cout << "ScavTrap constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
	// _name(copy._name), ??
{
	_name = copy._name;
	_hit_point = copy._hit_point;
	_energy_point = copy._energy_point;
	_attack_damage = copy._attack_damage;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &op)
{
	_name = op._name;
	_hit_point = op._hit_point;
	_energy_point = op._energy_point;
	_attack_damage = op._attack_damage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_hit_point <= 0 || _energy_point <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no more hit points or energy points to attack!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_point = this->_energy_point - 1;
}

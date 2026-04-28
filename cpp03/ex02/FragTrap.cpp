#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap Constructor called for " << this->_name << std::endl;
	return;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	this->_name = copy._name;
	this->_hit_point = copy._hit_point;
	this->_energy_point = copy._energy_point;
	this->_attack_damage = copy._attack_damage;
	std::cout << "FragTrap Copy constructor called for " << this->_name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &op) 
{
	if (this != &op)
	{
		ClapTrap::operator=(op);
		std::cout << "FragTrap Copy assignment operator overload called for " << this->_name << std::endl;
	}
	// this->_name = op._name;
	// this->_hit_point = op._hit_point;
	// this->_energy_point = op._energy_point;
	// this->_attack_damage = op._attack_damage;
	// std::cout << "FragTrap Copy assignment operator overload called for " << this->_name << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called for " << this->_name << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (_hit_point <= 0 || _energy_point <= 0)
	{
		std::cout << "FragTrap " << this->_name << " has no more hit points or energy points to attack!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_point = this->_energy_point - 1;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " requests a high five ! ✋😄" << std::endl;
}

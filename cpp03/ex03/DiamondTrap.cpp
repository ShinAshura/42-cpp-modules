#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string name) :
	ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	this->_hit_point = FragTrap::_hit_point;
	this->_energy_point = ScavTrap::_energy_point;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout << "DiamondTrap Constructor called for " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) :
	ClapTrap(copy), ScavTrap(copy), FragTrap(copy), _name(copy._name)
{
	_hit_point = copy._hit_point;
	_energy_point = copy._energy_point;
	_attack_damage = copy._attack_damage;
	std::cout << "DiamondTrap Copy constructor called for " << this->_name << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &op)
{
	if (this != &op)
	{
		ScavTrap::operator=(op);
		_name = op._name;
		std::cout << "DiamondTrap Copy assignment operator overload called for " << this->_name << std::endl;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called for " << this->_name << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	std::cout << "(DiamondTrap attack called)" << " : ";
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	// std::cout << "(whoAmI) DiamondTrap: " << this->_name << ", ClapTrap : " << ClapTrap::_name << std::endl; 
	std::cout << "(whoAmI) I am " << _name << ", and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

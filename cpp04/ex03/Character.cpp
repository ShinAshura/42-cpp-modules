#include <iostream>
#include <string>
#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

Character::Character() : _name("character_default_name"), _floorCount(0)
{
	// std::cout << "Character Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->_floor[i] = NULL;
}

Character::Character(const std::string &name) : _name(name), _floorCount(0)
{
	// std::cout << "Character Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->_floor[i] = NULL;
}

Character::Character(const Character &copy) : _name(copy._name), _floorCount(copy._floorCount)
{
	// std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	for (int i = 0; i < 100; i++)
	{
		if (copy._floor[i])
			this->_floor[i] = copy._floor[i]->clone();
		else
			this->_floor[i] = NULL;
	}
}

Character	&Character::operator=(const Character &op)
{
	if (this != &op)
	{
		// std::cout << "Character Copy assignment operator overload called" << std::endl;
		this->_name = op._name;

		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete (this->_inventory[i]);
			this->_inventory[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
		{
			if (op._inventory[i])
				this->_inventory[i] = op._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}

		for (int i = 0; i < 100; i++)
		{
			if (this->_floor[i])
				delete (this->_floor[i]);
			this->_floor[i] = NULL;
		}
		this->_floorCount = op._floorCount;
		for (int i = 0; i < 100; i++)
		{
			if (op._floor[i])
				this->_floor[i] = op._floor[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	// std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete (_inventory[i]);
	}
	for (int i = 0; i < 100; i++)
	{
		if (_floor[i])
			delete (_floor[i]);
	}
}

const std::string	&Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "Cannot equip a null Materia." << std::endl;
    	return;
	}
	for (int i = 0; i < 4; i++)
	{
		// re equip what was on the floor ?
		for (int j = 0; j < 100; j++)
		{
			if (this->_floor[j] == m && this->_inventory[i] == NULL)
			{
				// this->_inventory[i] = m;
				// this->_floor[j] = NULL;
				return;
			}
		}
		if (this->_inventory[i] == m)
		{
			std::cout << "Materia already equiped!" << std::endl;
			return;
		}
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return;
		}
	}
	std::cout << "Inventory is full" << std::endl;
}

void	Character::unequip(int index)
{
	if (index >= 0 && index < 4)
	{
		if (this->_inventory[index])
		{
			// this->_floor[_floorCount++] = this->_inventory[index];
			if (_floorCount < 100)
			{
				std::cout << "Unequiped " << this->_inventory[index]->getType() << " at index " << index << std::endl;
				this->_floor[_floorCount++] = this->_inventory[index];
			}
			else
				std::cout << "Warning: floor is full, can't save unequipped Materia." << std::endl;
			this->_inventory[index] = NULL;
		}
	}
	else
		std::cout << "No Materia in slot " << index << " to unequip." << std::endl;
		// std::cout << "Nothing to unequip" << std::endl;
}

void	Character::use(int index, ICharacter &target)
{
	if (index >= 0 && index < 4)
	{
		if (this->_inventory[index] != NULL)
			this->_inventory[index]->use(target);
		else
			std::cout << "Slot " << index << " is empty" << std::endl;
	}
	else
		// std::cout << "Nothing to use!" << std::endl;
		std::cout << "Index " << index << " out of range!" << std::endl;
}

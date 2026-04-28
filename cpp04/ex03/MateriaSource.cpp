#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

MateriaSource::MateriaSource() : _name("default_name")
{
	// std::cout << "MateriaSource Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	// std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (copy._materias[i] )
			this->_materias[i] = copy._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &op)
{
	if (this != &op)
	{
		// std::cout << "MateriaSource copy assignment operator overload called" << std::endl;

		// Free existing materias
		for (int i = 0; i < 4; i++)
		{
			if (this->_materias[i])
				delete (this->_materias[i]);
			this->_materias[i] = NULL;
		}

		for (int i = 0; i < 4; i++)
		{
			if (op._materias[i])
				this->_materias[i] = op._materias[i]->clone();
			else
			this->_materias[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_materias[i])
			delete (this->_materias[i]);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = m;
			return;
		}
	}
}

AMateria*	MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; i++)
		if (_materias[i] != NULL && _materias[i]->getType() == type)
			return (_materias[i]->clone());
	std::cout << "MateriaSource: unknown type \"" << type << "\" requested." << std::endl;
	return (0);
}

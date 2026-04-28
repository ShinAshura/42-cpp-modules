#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		MateriaSource &operator=(const MateriaSource &op);
		~MateriaSource();

		void		learnMateria(AMateria *m);
		AMateria	*createMateria(const std::string &type);


	private:
		std::string	_name;
		AMateria	*_materias[4];
};

#endif

#ifndef ICE_HPP
#define ICE_HPP
#include <iostream>
#include <string>
#include "AMateria.hpp"
// #include "ICharacter.hpp"

class	ICharacter;

class	Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &copy);
		Ice	&operator=(const Ice &op);
		~Ice();

		AMateria*	clone() const;
		void		use(ICharacter &target);
};

#endif

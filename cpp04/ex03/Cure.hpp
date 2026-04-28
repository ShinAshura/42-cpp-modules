#ifndef CURE_HPP
#define CURE_HPP
#include <iostream>
#include <string>
#include "AMateria.hpp"
// #include "ICharacter.hpp"

class	ICharacter;

class	Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &copy);
		Cure &operator=(const Cure &op);
		~Cure();

		AMateria*	clone() const;
		void		use(ICharacter &target);
};

#endif

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class	Character : public ICharacter
{
	public:
		Character();
		Character(const std::string &name);
		Character(const Character &copy);
		Character &operator=(const Character &op);
		~Character();

		const std::string	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int index);
		void				use(int index, ICharacter &target);

	private:
		std::string	_name;
		AMateria	*_inventory[4];
		AMateria	*_floor[100];
		int			_floorCount;
};

#endif

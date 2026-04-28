#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	{
		DiamondTrap	dt("dtName");

		// dt.highFivesGuys();
		dt.attack("ennemy");
		dt.whoAmI();
	}

	{
		std::cout << "\n=== Copy Constructor and Assignment Test ===" << std::endl;
		DiamondTrap a("Original");
		DiamondTrap b = a;
		DiamondTrap c("Other");
		c = b;
	}


	return (0);
}

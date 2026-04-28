#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	{
		FragTrap ft("ftName");

		for (int i = 0; i < 100; i++)
			ft.attack("ennemy");

		// ft.takeDamage(100);
		// ft.takeDamage(99);
		// ft.beRepaired(99);
		// ft.takeDamage(99);

		ft.attack("ennemy");
		ft.highFivesGuys();
		// ft.guardGate();  => not possible since it belongs to ScavTrap
	}

	// {
	// 	FragTrap fg("FG");
	// 	fg.attack("target");
	// 	fg.takeDamage(30);
	// 	fg.beRepaired(20);

	// 	FragTrap fgCopy(fg);
	// 	FragTrap fgAssign("Assign");
	// 	fgAssign = fgCopy;

	// 	fgCopy.highFivesGuys();
	// 	fgCopy.attack("target");
	// 	fgCopy.takeDamage(30);
	// 	fgCopy.beRepaired(20);

	// 	fgAssign.highFivesGuys();
	// 	fgAssign.attack("target");
	// 	fgAssign.takeDamage(30);
	// 	fgAssign.beRepaired(20);
	// }

	// {
	// 	std::cout << "\n=== Copy Constructor and Assignment Test ===" << std::endl;
	// 	FragTrap a("Original");
	// 	FragTrap b(a);
	// 	FragTrap c("other");
	// 	c = a;
	// }


	return (0);
}

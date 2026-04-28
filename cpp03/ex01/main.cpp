#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	{
		ScavTrap sv("svName");

		// for (int i = 0; i < 50; i++)
		// 	sv.attack("ennemy");

		// sv.takeDamage(100);
		sv.takeDamage(99);
		sv.beRepaired(99);
		sv.takeDamage(99);

		sv.attack("ennemy");
		sv.guardGate();
	}


	// std::cout << std::endl << std::endl;
	// {
	// 	std::cout << "=== ScavTrap Creation ===" << std::endl;
	// 	ScavTrap sv("SV");
	// 	std::cout << std::endl;

	// 	std::cout << "=== ScavTrap Actions ===" << std::endl;
	// 	sv.attack("Target");
	// 	sv.guardGate();
	// 	sv.takeDamage(20);
	// 	sv.beRepaired(10);
	// 	std::cout << std::endl;

	// 	std::cout << "=== Copy & Assignment ===" << std::endl;
	// 	ScavTrap copySv(sv);
	// 	ScavTrap assignSv("Tmp");
	// 	assignSv = sv;
	// 	std::cout << std::endl;

	// 	std::cout << "=== Destruction ===" << std::endl;
	// }

	return (0);
}

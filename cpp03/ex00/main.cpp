#include <iostream>
#include <string>
#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	cp("cp_name");
	
	cp.attack("target_name");
	cp.takeDamage(5);
	// cp.takeDamage(5);
	cp.attack("target_name");
	cp.attack("target_name");
	cp.attack("target_name");
	cp.attack("target_name");
	cp.attack("target_name");
	cp.attack("target_name");
	cp.attack("target_name");
	cp.attack("target_name");
	cp.attack("target_name10");
	cp.attack("target_name11");
	cp.beRepaired(5);
	cp.attack("target_name");

	// std::cout << std::endl << "======================================" << std::endl;

	// {
	// 	std::cout << "=== Basic Construction ===" << std::endl;
	// 	ClapTrap a("Alpha");
	// 	std::cout << std::endl;

	// 	std::cout << "=== Copy Construction ===" << std::endl;
	// 	ClapTrap b(a);
	// 	std::cout << std::endl;

	// 	std::cout << "=== Assignment Operator ===" << std::endl;
	// 	ClapTrap c("Charlie");
	// 	c = b;
	// 	std::cout << std::endl;

	// 	std::cout << "=== Basic Actions ===" << std::endl;
	// 	a.attack("Enemy1");
	// 	a.takeDamage(3);
	// 	a.beRepaired(2);
	// 	std::cout << std::endl;

	// 	std::cout << "=== Energy Depletion Test ===" << std::endl;
	// 	for (int i = 0; i < 11; ++i)
	// 		a.attack("DummyTarget"); // Should stop after 10
	// 	std::cout << std::endl;

	// 	std::cout << "=== Health Depletion Test ===" << std::endl;
	// 	a.takeDamage(100); 			// Should bring to 0
	// 	a.attack("AnotherTarget");	// Should do nothing
	// 	a.beRepaired(5);			// Should do nothing
	// 	std::cout << std::endl;

	// 	std::cout << "=== Destruction Chain ===" << std::endl;
	// }

	return (0);
}

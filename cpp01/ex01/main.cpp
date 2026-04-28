#include <iostream>
#include <string>
#include "Zombie.hpp"

int	main()
{
	Zombie*	zsh;

	zsh = zombieHorde(10, "zombie_Horde");

	if (zsh)
	{
		for (int i = 0; i < 10; i++)
			zsh[i].announce();
		//delete[] zsh;
	}
	else
		std::cerr << "Failed to create a zombie Horde" << std::endl;
	// zsh->announce();
	delete [] zsh;
	return (0);
}
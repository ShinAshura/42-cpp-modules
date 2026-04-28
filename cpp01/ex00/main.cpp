#include <iostream>
#include <string>
#include "Zombie.hpp"

int	main(void)
{

	
	Zombie	zombie("Foo");
	Zombie*	newZombiePtr = newZombie("newFoo");

	zombie.announce();
	newZombiePtr->announce();
	randomChump("randomChump");
	delete	newZombiePtr;
	return (0);
}

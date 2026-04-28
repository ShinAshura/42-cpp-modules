#include <iostream>
#include <string>
#include <sstream>
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N < 0)
		return (NULL);

	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		std::stringstream	ss;
		ss << name << "_" << i;
		horde[i].setName(ss.str());
		// horde[i].announce();
	}
	return (horde);
}
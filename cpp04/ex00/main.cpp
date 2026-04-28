#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
		delete j;
	}

	{
		std::cout << "\n===============" << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the WrongAnimal sound
		meta->makeSound();

		delete meta;
		delete i;

		const WrongAnimal* animal = new WrongCat();
		delete animal; // 🔥 Only WrongAnimal::~WrongAnimal() is called!
	}

	{
		std::cout << "\n===============" << std::endl;
		Animal	a;  // instantiate Animal class
		Dog	d;
		d.makeSound();
	}

	return 0;
}
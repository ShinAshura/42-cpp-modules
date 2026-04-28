#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		// AAnimal	a;  // ERROR: cannot instantiate abstract class
		Dog	d;
		d.makeSound();
	}

	{
		std::cout << "\n==================== 42 main ====================" << std::endl;
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}



	// {
	// 	std::cout << "\n==================== 42 main subject ====================" << std::endl;
	// 	AAnimal	*animal[100];
		
	// 	for (int i = 0; i < 50; i++)
	// 	{
	// 		std::cout << i;
	// 		animal[i] = new Dog();
	// 	}
	// 	for (int i = 50; i < 100; i++)
	// 	{
	// 		std::cout << i;
	// 		animal[i] = new Cat();
	// 	}

	// 	for (int i = 0; i < 100; i++)
	// 	{
	// 		std::cout << i;
	// 		delete animal[i];
	// 	}
	// }



	std::cout << "\n==================== Deep copy test ====================" << std::endl;
	{
		Dog dog1;
		dog1.setIdea(0, "Eat bones");

		Dog dog2 = dog1;

		dog1.setIdea(0, "Chase cats");

		std::cout << "dog1 idea: " << dog1.getIdea(0) << std::endl;
		std::cout << "dog2 idea: " << dog2.getIdea(0) << std::endl;
		// Deep Copies 
		//				 dog1 idea: Chase cats
		//				 dog2 idea: Eat bones
	}




	// test no leaks for delete in copy assignment operator overload
	// Dog dog1;
	// Dog dog2;

	// dog1.setIdea(0, "Fetch stick");
	// dog2 = dog1; // Calls operator=



	return 0;
}
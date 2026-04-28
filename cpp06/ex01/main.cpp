#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"
#include "Serializer.hpp"

int	main()
{
	// Serializer	test; // not instanciable (initializable)

	Data	original;
	original.name = "ogName";
	original.value = 42;

	uintptr_t	raw = Serializer::serialize(&original);
	Data* 		copy = Serializer::deserialize(raw);

	std::cout << "og Name: " << copy->name << ", og Value: " << copy->value << std::endl;
	std::cout << "Original Address: " << &original << std::endl;
	std::cout << "Copy Address    : " << copy << std::endl;
	std::cout << "copy Name: " << copy->name << ", copy Value: " << copy->value << std::endl;

	return 0;
}

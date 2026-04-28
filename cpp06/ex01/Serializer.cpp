#include <iostream>
#include <string>
#include <stdint.h>
#include "Serializer.hpp"
#include "Data.hpp"

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}


Serializer::Serializer()
{

}

Serializer::Serializer(const Serializer &copy)
{
	(void)copy;
}

Serializer &Serializer::operator=(const Serializer &op)
{
	(void)op;
	return (*this);
}

Serializer::~Serializer()
{

}

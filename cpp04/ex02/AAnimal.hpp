#ifndef AANIMAL_HPP
#define AANIMAL_HPP
#include <iostream>
#include <string>

class	AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal &copy);
		AAnimal &operator=(const AAnimal &op);
		virtual ~AAnimal();

		virtual void		makeSound() const = 0;
		virtual std::string	getType() const;

	protected:
		std::string _type;
};

#endif

#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class	Dog : public AAnimal
{
	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &op);
		virtual ~Dog();

		virtual void		makeSound() const;
		virtual std::string	getType() const;

		void				setIdea(int index, const std::string idea);
		std::string			getIdea(int index);

	private:
		Brain	*_brain;
};

#endif

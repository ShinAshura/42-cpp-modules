#ifndef CAT_HPP
#define CAT_HPP
#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &op);
		virtual ~Cat();

		virtual void		makeSound() const;
		virtual std::string	getType() const;

	private:
		Brain	*_brain;
};

#endif

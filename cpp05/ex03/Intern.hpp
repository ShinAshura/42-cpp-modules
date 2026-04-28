#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include <string>
#include "AForm.hpp"

// class	AForm;

class	Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &op);
		~Intern();

		AForm*	makeForm(const std::string &formName, const std::string &formTarget);
};

// typedef	AForm* (*FormCreator)(const std::string &target);

#endif

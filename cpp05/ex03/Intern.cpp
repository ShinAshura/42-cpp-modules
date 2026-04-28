#include <iostream>
#include <string>
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern	&Intern::operator=(const Intern &op)
{
	(void)op;
	return (*this);
}

Intern::~Intern()
{

}

static AForm*	createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm*	createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm*	createPresident(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
	typedef	AForm* (*FormCreator)(const std::string &target);

	const std::string formNames[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	FormCreator creators[3] =
	{
		&createShrubbery,
		&createRobotomy,
		&createPresident
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](formTarget);
		}
	}

	std::cout << "Intern couldn't create the form " << formName << std::endl;
	return (NULL);
}

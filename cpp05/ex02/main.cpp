#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	std::cout << "============= TEST SHRUBBERY =============" << std::endl;
	AForm	*shrub = NULL;
	try
	{
		shrub = new ShrubberyCreationForm("home");
		Bureaucrat john("john", 137);

		john.signForm(*shrub);
		shrub->execute(john);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught : " << e.what() << std::endl;
	}


	std::cout << "\n============= TEST ROBOTOMY =============" << std::endl;
	AForm	*robot = NULL;
	try
	{
		robot = new RobotomyRequestForm("bocal");
		Bureaucrat	doe("doe", 45);

		doe.signForm(*robot);
		robot->execute(doe);
		doe.executeForm(*robot);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught : " << e.what() << std::endl;
	}


	std::cout << "\n============= TEST PRESIDENT =============" << std::endl;
	AForm	*president = NULL;
	try
	{
		president = new PresidentialPardonForm("president");
		Bureaucrat	johnDoe("johnDoe", 5);

		// johnDoe.executeForm(*president); // throw exception and quit without executing whats next
		johnDoe.signForm(*president);
		johnDoe.signForm(*president);
		johnDoe.executeForm(*president);
		johnDoe.executeForm(*president);
		president->execute(johnDoe);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught : " << e.what() << std::endl;
	}


	delete shrub;
	delete robot;
	delete president;

	return (0);
}

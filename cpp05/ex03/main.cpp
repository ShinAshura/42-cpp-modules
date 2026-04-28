#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	{
		std::cout << "============= TEST ROBOTOMY =============" << std::endl;
		AForm*	rrf = NULL;
		try
		{
			Intern someRandomIntern;
			// AForm* rrf;
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			if (!rrf)
				return (1);

			Bureaucrat john("john", 45);

			john.signForm(*rrf);
			rrf->execute(john);

			delete rrf;
		}
		catch (std::exception &e)
		{
			if (rrf)
				delete rrf;
			std::cout << "Exception caught : " << e.what() << std::endl;
		}

		std::cout << "\n============= TEST SHRUB =============" << std::endl;
		AForm*	shrub = NULL;
		try
		{
			Intern	anotherIntern;
			// AForm	*shrub;
			Bureaucrat	doe("doe", 137);

			shrub = anotherIntern.makeForm("shrubbery creation", "homeSweetHome");
			if (!shrub)
				return (1);

			doe.signForm(*shrub);
			shrub->execute(doe);

			delete shrub;
		}
		catch (std::exception &e)
		{
			if (shrub)
				delete shrub;
			std::cout << "Exception caught : " << e.what() << std::endl;
		}

		std::cout << "\n============= TEST PRESIDENT =============" << std::endl;
		AForm*	pres = NULL;
		try
		{
			Intern	andAnotherIntern;
			// AForm	*shrub;
			Bureaucrat	johnDoe("johnDoe", 3);

			pres = andAnotherIntern.makeForm("presidential pardon", "sheesh");
			if (!pres)
				return (1);

			johnDoe.signForm(*pres);
			pres->execute(johnDoe);

			delete pres;
		}
		catch (std::exception &e)
		{
			if (pres)
				delete pres;
			std::cout << "Exception caught : " << e.what() << std::endl;
		}

		std::cout << "\n============= TEST FORM DOES NOT EXIST =============" << std::endl;
		AForm*	bonus = NULL;
		try
		{
			Intern	andAnotherOne;
			// AForm	*shrub;
			Bureaucrat	johnCena("johnCena", 138);

			bonus = andAnotherOne.makeForm("Salary augmentation form", "bonus");
			if (!bonus)
				return (1);

			johnCena.signForm(*bonus);
			bonus->execute(johnCena);

			// if (bonus)
				delete bonus;
		}
		catch (std::exception &e)
		{
			if (bonus)
				delete bonus;
			std::cout << "Exception caught : " << e.what() << std::endl;
		}
	}


	
	// {
	// 	std::cout << "\n\n============= TEST SHRUBBERY =============" << std::endl;
	// 	AForm	*shrub = NULL;
	// 	try
	// 	{
	// 		shrub = new ShrubberyCreationForm("home");
	// 		Bureaucrat john("john", 137);

	// 		john.signForm(*shrub);
	// 		shrub->execute(john);
	// 	}
	// 	catch (std::exception &e)
	// 	{
	// 		std::cout << "Exception caught : " << e.what() << std::endl;
	// 	}


	// 	std::cout << "\n============= TEST ROBOTOMY =============" << std::endl;
	// 	AForm	*robot = NULL;
	// 	try
	// 	{
	// 		robot = new RobotomyRequestForm("bocal");
	// 		Bureaucrat	doe("doe", 45);

	// 		doe.signForm(*robot);
	// 		robot->execute(doe);
	// 		doe.executeForm(*robot);
	// 	}
	// 	catch (std::exception &e)
	// 	{
	// 		std::cout << "Exception caught : " << e.what() << std::endl;
	// 	}


	// 	std::cout << "\n============= TEST PRESIDENT =============" << std::endl;
	// 	AForm	*president = NULL;
	// 	try
	// 	{
	// 		president = new PresidentialPardonForm("president");
	// 		Bureaucrat	johnDoe("johnDoe", 5);

	// 		// johnDoe.executeForm(*president); // throw exception and quit without executing whats next
	// 		johnDoe.signForm(*president);
	// 		johnDoe.signForm(*president);
	// 		johnDoe.executeForm(*president);
	// 		johnDoe.executeForm(*president);
	// 		president->execute(johnDoe);
	// 	}
	// 	catch (std::exception &e)
	// 	{
	// 		std::cout << "Exception caught : " << e.what() << std::endl;
	// 	}


	// 	delete shrub;
	// 	delete robot;
	// 	delete president;
	// }

	return (0);
}

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

int	main()
{
	// try
	// {
	// 	Bureaucrat	intmax("intmax", 2147483648);
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << "Exception caught : " << e.what() << std::endl;
	// }

	// try
	// {
	// 	Bureaucrat	intmin("intmin", -2147483649);
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << "Exception caught : " << e.what() << std::endl;
	// }

	try
	{
		Bureaucrat	bob("bob", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught : " << e.what() << std::endl;
	}
//////////////////////////////////////////////////////////////////////
	try
	{
		Bureaucrat	Alice("Alice", 170);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught : " << e.what() << std::endl;
	}


	
	std::cout << "\n========== basic test ==========" << std::endl;
	try
	{
		Bureaucrat	test("test", 10);
		std::cout << test << std::endl;
		std::cout << "name : " << test.getName() << std::endl;
		std::cout << "grade : " << test.getGrade() << std::endl;
		test.incrementGrade();
		std::cout << "grade : " << test.getGrade() << std::endl;
		test.incrementGrade();
		std::cout << "grade : " << test.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught : " << e.what() << std::endl;
	}

	std::cout << "\n========== TEST ==========" << std::endl;
	Bureaucrat	*john = NULL;
	try
	{
		john = new Bureaucrat("John", 2);

		std::cout << *john << std::endl;
		std::cout << "name : " << john->getName() << std::endl;
		std::cout << "grade : " << john->getGrade() << std::endl;
		john->incrementGrade();
		std::cout << "grade : " << john->getGrade() << std::endl;
		john->incrementGrade();
		std::cout << "grade : " << john->getGrade() << std::endl;

		delete john;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught : " << e.what() << std::endl;
	}
	// if (john)
	// {
	// 	std::cout << *john << std::endl;
	// 	std::cout << "name : " << john->getName() << std::endl;
	// 	std::cout << "grade : " << john->getGrade() << std::endl;
	// 	john->incrementGrade();
	// 	std::cout << "grade : " << john->getGrade() << std::endl;
	// 	john->incrementGrade();
	// 	std::cout << "grade : " << john->getGrade() << std::endl;
	// }


	std::cout << "========== TEST2 ==========" << std::endl;
	Bureaucrat *doe = NULL;
	try
	{
		doe = new Bureaucrat("doe", 149);

		std::cout << *doe << std::endl;
		std::cout << "name : " << doe->getName() << std::endl;
		std::cout << "grade : " << doe->getGrade() << std::endl;
		doe->decrementGrade();
		std::cout << "grade : " << doe->getGrade() << std::endl;
		doe->decrementGrade();
		std::cout << "grade : " << doe->getGrade() << std::endl;

		delete doe;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught : " << e.what() << std::endl;
	}
	// if (doe)
	// {
	// 	std::cout << *doe << std::endl;
	// 	std::cout << "name : " << doe->getName() << std::endl;
	// 	std::cout << "grade : " << doe->getGrade() << std::endl;
	// 	doe->decrementGrade();
	// 	std::cout << "grade : " << doe->getGrade() << std::endl;
	// 	doe->decrementGrade();
	// 	std::cout << "grade : " << doe->getGrade() << std::endl;
	// }


	delete john;
	delete doe;

	return (0);
}

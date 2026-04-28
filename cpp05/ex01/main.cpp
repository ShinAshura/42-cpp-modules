#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << "==== Test1 ====" << std::endl;
	Bureaucrat	john("john", 50);
	Form		leaveRequest("leaveRequest", 75, 50);
	std::cout << leaveRequest << std::endl;
	john.signForm(leaveRequest);
	std::cout << leaveRequest << std::endl;
	john.signForm(leaveRequest);
	std::cout << leaveRequest << std::endl;


	std::cout << "\n==== Test2 ====" << std::endl;
	Bureaucrat	doe("doe", 80);
	Form		leaveRequest2("leaveRequest", 75, 50);
	std::cout << leaveRequest2 << std::endl;
	doe.signForm(leaveRequest2);
	std::cout << leaveRequest2 << std::endl;

	return (0);
}

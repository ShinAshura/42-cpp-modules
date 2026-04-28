#include <iostream>
#include <string>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("defaultTarget", 72, 45), _target("defaultTarget")
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{

}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &op)
{
	if (this != &op)
	{
		this->_target = op._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void	RobotomyRequestForm::executeAction() const
{
	// if (this->isSigned() == false)
	// 	throw AForm::GradeTooLowException();
	// if (executor.getGrade() > this->getExecuteGrade())
	// 	throw AForm::GradeTooLowException();

	std::cout << "Some drilling sound.... Bzzzzzzz...." << std::endl;
	srand((unsigned) time(NULL));
	if (rand() % 2 == 0)
		std::cout << this->_target + " has been robotomized successfully !" << std::endl;
	else
		std::cout << "Robotomy failed !" << std::endl;
}

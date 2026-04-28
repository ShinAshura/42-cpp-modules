#include <iostream>
#include <string>
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("defaultTarget", 25, 5), _target("defaultTarget")
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(target, 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target)
{

}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &op)
{
	if (this != &op)
	{
		this->_target = op._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void	PresidentialPardonForm::executeAction() const
{
	// if (this->isSigned() == false)
	// 	throw GradeTooLowException();
	// if (executor.getGrade() > this->getExecuteGrade())
	// 	throw GradeTooLowException();
	
	std::cout << this->_target + " has been pardonned by Zaphod Beeblebrox" << std::endl;
}

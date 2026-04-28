#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name("defaultName"), _signed(false), _signGrade(150), _executeGrade(150)
{

}

AForm::AForm(const std::string &name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(execGrade)
{
	if (_signGrade < 1 || _executeGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade)
{

}

AForm	&AForm::operator=(const AForm &op)
{
	if (this != &op)
	{
		this->_signed = op._signed;
		//  _name, _signGrade, and _executeGrade are const and cannot be reassigned
		// this->_name = op._name;
		// this->_signGrade = op._signGrade;
		// this->_executeGrade = op._executeGrade;
	}
	return (*this);
}

AForm::~AForm()
{

}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Grade too High";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Grade too Low";
}

const char*	AForm::AlreadySignedException::what() const throw()
{
	return "Form already signed !!!!!!!!!!!";
}

const std::string	&AForm::getName() const
{
	return (this->_name);
}

bool	AForm::isSigned() const
{
	if (this->_signed)
		return (true);
	return (false);
}

int	AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int	AForm::getExecuteGrade() const
{
	return (this->_executeGrade);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->isSigned() == true)
		throw AlreadySignedException();
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = true;
}
// void	AForm::beSigned(const Bureaucrat &bureaucrat)
// {
// 	if (bureaucrat.getGrade() <= this->_signGrade)
// 		this->_signed = true;
// 	else
// 		throw GradeTooLowException();
// }

void	AForm::execute(const Bureaucrat &executor) const
{
	if (this->isSigned() == false)
		throw GradeTooLowException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();

	this->executeAction();
}


std::ostream	&operator<<(std::ostream &out, const AForm &form)
{
	// out << form.getName() << ", required sign grade : " << form.getSignGrade() << ", required execute grade : " << form.getExecuteGrade();
	out << "Form \"" << form.getName()
    << "\" [sign grade: " << form.getSignGrade()
    << ", execute grade: " << form.getExecuteGrade()
    << ", signed: " << (form.isSigned() ? "yes" : "no") << "]";
	return (out);
}

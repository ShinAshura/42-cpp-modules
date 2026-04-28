#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("defaultName"), _signed(false), _signGrade(150), _executeGrade(150)
{

}

Form::Form(const std::string &name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(execGrade)
{
	if (_signGrade < 1 || _executeGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade)
{

}

Form	&Form::operator=(const Form &op)
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

Form::~Form()
{

}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Grade too High";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Grade too Low";
}

const char*	Form::AlreadySignedException::what() const throw()
{
	return "Form already signed !!!!!!!!!!!";
}

const std::string	&Form::getName() const
{
	return (this->_name);
}

bool	Form::isSigned() const
{
	if (this->_signed)
		return (true);
	return (false);
}

int	Form::getSignGrade() const
{
	return (this->_signGrade);
}

int	Form::getExecuteGrade() const
{
	return (this->_executeGrade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->isSigned() == true)
		throw AlreadySignedException();
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = true;
}



std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	// out << form.getName() << ", required sign grade : " << form.getSignGrade() << ", required execute grade : " << form.getExecuteGrade();
	out << "Form \"" << form.getName()
    << "\" [sign grade: " << form.getSignGrade()
    << ", execute grade: " << form.getExecuteGrade()
    << ", signed: " << (form.isSigned() ? "yes" : "no") << "]";
	return (out);
}

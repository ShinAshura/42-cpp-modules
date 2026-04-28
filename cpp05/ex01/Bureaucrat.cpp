#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("defaultName"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{

}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &op)
{
	if (this != &op)
		this->_grade = op._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{

}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too High";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too Low";
}

const std::string	&Bureaucrat::getName() const
{
	return (this->_name);
}

int					Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
	// this->_grade -= 1;
}
// std::cout << "Grade already the highest (greatest of all time!)" << std::endl;


void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
	// this->_grade += 1;
}
// std::cout << "Grade already at the lowest point" << std::endl << "SHOW THEM YOU CAN CLIMB FROM IRON TO CHALLENGER!" << std::endl;


std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << " form" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

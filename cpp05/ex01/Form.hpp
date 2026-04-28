#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	Form
{
	public:
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	AlreadySignedException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};

		Form();
		Form(const std::string &name, int signGrade, int execGrade);
		Form(const Form &copy);
		Form &operator=(const Form &op);
		~Form();

		const std::string	&getName() const;
		bool				isSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		void				beSigned(const Bureaucrat &bureaucrat);

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;
};

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif

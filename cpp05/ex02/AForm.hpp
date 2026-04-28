#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	AForm
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
	
	AForm();
	AForm(const std::string &name, int signGrade, int execGrade);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &op);
	virtual ~AForm();
	
	const std::string	&getName() const;
	bool				isSigned() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;
	
	void				beSigned(const Bureaucrat &bureaucrat);
	
	void	execute(const Bureaucrat &executor) const; 

	protected:
		virtual void	executeAction() const = 0;

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;
};

std::ostream	&operator<<(std::ostream &out, const AForm &form);

#endif

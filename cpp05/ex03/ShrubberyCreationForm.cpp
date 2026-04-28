#include <iostream>
#include <string>
#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("defaultTarget" , 145, 137), _target("defaultTarget")
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target , 145, 137), _target(target)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{

}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &op)
{
	if (this != &op)
	{
		this->_target = op._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

// std::string	ShrubberyCreationForm::getTarget()
// {
// 	return (this->_target);
// }

void	ShrubberyCreationForm::executeAction() const
{
	// if (this->isSigned() == false)
	// 	throw AForm::GradeTooLowException();
	// if (executor.getGrade() > this->getExecuteGrade())
	// 	throw AForm::GradeTooLowException();

	// std::string		filename = this->_target + "_shrubbery";
	// std::ofstream	ofs(filename.c_str());
	std::ofstream	ofs((this->_target + "_shrubbery").c_str());
	if (!ofs.is_open())
	{
		std::cerr << "Error ofs" << std::endl;
		return;
	}
	ofs <<"                                                         .\n" <<
"                                              .         ;\n" <<
"                 .              .              ;%     ;;   \n" <<
"                   ,           ,                :;%  %;   \n" <<
"                    :         ;                   :;%;'     .,   \n" <<
"           ,.        %;     %;            ;        %;'    ,;\n" <<
"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n" <<
"              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n" <<
"               ;%;      %;        ;%;        % ;%;  ,%;'\n" <<
"                `%;.     ;%;     %;'         `;%%;.%;'\n" <<
"                 `:;%.    ;%%. %@;        %; ;@%;%'\n" <<
"                    `:%;.  :;bd%;          %;@%;'\n" <<
"                      `@%:.  :;%.         ;@@%;'   \n" <<
"                        `@%.  `;@%.      ;@@%;         \n" <<
"                          `@%%. `@%%    ;@@%;        \n" <<
"                            ;@%. :@%%  %@@%;       \n" <<
"                              %@bd%%%bd%%:;     \n" <<
"                                #@%%%%%:;;\n" <<
"                                %@@%%%::;\n" <<
"                                %@@@%(o);  . '         \n" <<
"                                %@@@o%;:(.,'         \n" <<
"                            `.. %@@@o%::;         \n" <<
"                               `)@@@o%::;         \n" <<
"                                %@@(o)::;        \n" <<
"                               .%@@@@%::;         \n" <<
"                               ;%@@@@%::;.          \n" <<
"                              ;%@@@@%%:;;;. \n" <<
"                          ...;%@@@@@%%:;;;;,.." << std::endl;

	ofs.close();
	
	std::cout << this->_target + "_shrubbery file created" << std::endl;
}

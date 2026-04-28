#include "RPN.hpp"
#include <sstream>

RPN::RPN() {}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &op)
{
	(void)op;
	return (*this);
}

RPN::~RPN() {}

bool	RPN::isValidArg(const std::string &pme)
{
	int i = 0;

	while (pme[i])
	{
		if (!isdigit(pme[i]) && pme[i] != '+' && pme[i] != '-' && pme[i] != '*' && pme[i] != '/' && pme[i] != ' ')
			return false;
		i++;
	}

	return true;
}

bool	RPN::isOp(const std::string &token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool	RPN::isNumber(const std::string &token, int &value)
{
	std::istringstream	ss(token);
	ss >> value;
	return !ss.fail() && ss.eof();
}


void	RPN::calculate(const std::string &pme)
{
	std::stack<int>		istack;
	std::istringstream	ss(pme);
	std::string			token;

	while (ss >> token)
	{
		if (isdigit(token[0]))
		{
			for (size_t i = 0; i < token.size(); i++)
			{
				if (!isdigit(token[i]))
				{
					std::cerr << "Error: invalid digit in number" << std::endl;
					return;
				}
				istack.push(token[i] - '0');
			}
		}
		else if (isOp(token))
		{
			if (istack.size() < 2)
			{
				std::cerr << "Error: Invalid expression (not enough operands)" << std::endl;
				// std::cerr << "Error" << std::endl;
				return;
			}

			int second = istack.top();
			istack.pop();

			int first = istack.top();
			istack.pop();

			int	res = 0;
			if (token == "+")
				res = first + second;
			else if (token == "-")
				res = first - second;
			else if (token == "*")
				res = first * second;
			else if (token == "/")
			{
				if (second == 0)
				{
					// std::cerr << "Error" << std::endl;
					std::cerr << "Error: Division by zero" << std::endl;
					return;
				}
				res = first / second;
			}
			istack.push(res);
		}
		else
		{
			std::cerr << "Error: Invalid token" << std::endl;
			return;
		}
	}
	if (istack.size() != 1)
	{		
		std::cerr << "Error : Invalid expression (final stack doesn't have only 1 number)" << std::endl;
		// std::cerr << "Error" << std::endl;
		return;
	}
	std::cout << istack.top() << std::endl;
}

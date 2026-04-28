#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <string>
#include <stack>

class	RPN
{
	public:
		RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &op);
		~RPN();

		static bool	isValidArg(const std::string &pme);

		static void	calculate(const std::string &pme);

	private:
		static bool	isOp(const std::string &token);
		static bool	isNumber(const std::string &token, int &value);
};

#endif

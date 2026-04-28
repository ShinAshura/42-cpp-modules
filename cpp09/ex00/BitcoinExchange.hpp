#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <string>
#include <map>

class	BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &data);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &op);
		~BitcoinExchange();

		void	parseInput(const std::string &input);

	private:
		std::map<std::string, float>	_exRates;

		bool		isValidDate(const std::string &date);
		bool		isValidValue(const std::string &valueStr, float &value);
		std::string	trim(const std::string &str);
};

#endif

#include <iostream>
#include <string>
#include <fstream>
#include <map>
// #include <iomanip>
// #include <algorithm>
#include <cstdlib>
// #include <limits>
#include <sstream>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _exRates(copy._exRates)
{

}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &op)
{
	if (this != &op)
		_exRates = op._exRates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}


BitcoinExchange::BitcoinExchange(const std::string &input)
{
	std::ifstream	ifs(input.c_str());
	if (!ifs.is_open())
		throw std::runtime_error("Cannot open input file");
	
	std::string	line;
	std::getline(ifs, line);
	while (std::getline(ifs, line))
	{
		std::istringstream ss(line);
		std::string date;
		std::string	rateStr;

		if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
			continue;

		std::istringstream	rs(rateStr);
		float	rate;
		if (!(rs >> rate))
			continue;
		_exRates[date] = rate;

		// _exRates[date] = std::atof(rateStr.c_str());
	}
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (isLeapYear && month == 2)
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;
}

bool	BitcoinExchange::isValidValue(const std::string &valueStr, float &value)
{
	std::istringstream	ss(valueStr);
	ss >> value;
	if (ss.fail() || !ss.eof() || value < 0 || value > 1000)
		return false;
	return true;
}

std::string	BitcoinExchange::trim(const std::string &str)
{
	size_t	start = str.find_first_not_of(" \t");
	size_t	end = str.find_last_not_of(" \t");
	return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

void	BitcoinExchange::parseInput(const std::string &inputFile)
{
	std::ifstream	ifs(inputFile.c_str());
	if (!ifs || !ifs.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string	line;
	std::getline(ifs, line);
	// if (std::getline(ifs, line) == NULL)
	// {
	// 	std::cerr << "Input file empty." << std::endl;
	// 	return;
	// }
	while (std::getline(ifs, line))
	{
		size_t	pipe = line.find('|');
		if (pipe == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string	date = trim(line.substr(0, pipe));
		std::string	valueStr = trim(line.substr(pipe + 1));

		float value;
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input date => " << date << std::endl;
			// std::cerr << "Error: bad input => " << line << std::endl;
		}
		else if (!isValidValue(valueStr, value))
		{
			if (value > 1000)
				std::cerr << "Error: too large a number." << std::endl;
			else if (value < 0)
				std::cerr << "Error: not a positive number." << std::endl; 
		}
		else
		{
			std::map<std::string, float>::iterator it = _exRates.lower_bound(date);
			if (it == _exRates.end() || it->first != date)
			{
				if (it == _exRates.begin())
				{
					std::cerr << "Error: no earlier date found for " << date << std::endl;
					continue;
				}
				it--;
			}
			// float result = value * it->second;
			std::cout << date << " => " << value << " = " << value * it->second << std::endl;
			// std::cout << date << " => " << value << " = " << std::fixed << std:: setprecision(2) << result << std::endl;
		}
	}
}

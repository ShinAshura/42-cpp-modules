#include <iostream>
#include "Span.hpp"
#include <limits>
#include <algorithm>
#include <stdexcept>

Span::Span() : _n(0) {}

Span::Span(unsigned int N) : _n(N)
{
	
}

Span::Span(const Span &copy) : _numbers(copy._numbers), _n(copy._n)
{

}

Span	&Span::operator=(const Span &op)
{
	if (this != &op)
	{
		this->_n = op._n;
		this->_numbers = op._numbers;
	}
	return (*this);
}

Span::~Span() {}


const char*	Span::AlreadyFull::what() const throw()
{
	return "Container already full";
}

const char*	Span::Flow::what() const throw()
{
	return "Underflow / Overflow of INT";
}


void	Span::addNumber(long long number)
{
	if (number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
		throw Flow();
	if (this->_numbers.size() >= this->_n)
		throw AlreadyFull();
	this->_numbers.push_back(number);
}

int	Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to get a span. (needs at least 2");

	std::vector<int>	sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int	shortSpan = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++)
		shortSpan = std::min(shortSpan, sorted[i] - sorted[i - 1]);
	
	return shortSpan;
}

int	Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to get a span. (needs at least 2");

	std::vector<int>	sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int	longSpan = sorted.back() - sorted.front();

	return longSpan;
}

// Less verbose ? 
// int	Span::longestSpan()
// {
// 	if (_numbers.size() < 2)
// 		throw std::logic_error("Not enough numbers to get a span. (needs at least 2");

// 	int	min = *std::min_element(_numbers.begin(), _numbers.end());
// 	int	max = *std::max_element(_numbers.begin(), _numbers.end());

// 	return max - min;
// }


void	Span::addRange(unsigned int start, unsigned int end)
{
	if (end - start > _n)
		throw std::logic_error("Range too big");
	if (start > end)
		throw std::logic_error("Range invalid (start need to be smaller than end)");

	srand((unsigned) time(NULL));
	for (unsigned int i = 0; i < end - start; i++)
		this->addNumber(rand());
		// _numbers.push_back(i * 2);
	std::cout << "Size : " << _numbers.size() << std::endl;
}


void	Span::addRangeRand(unsigned int range)
{
	if (range > _n)
		throw std::logic_error("Range too big");

	srand((unsigned) time(NULL));
	for (unsigned int i = 0; i < range; i++)
		this->addNumber(rand());
		// _numbers.push_back(rand());
	std::cout << "Size : " << _numbers.size() << std::endl;
}


// void	Span::multipleAdd()
// {
// 	srand((unsigned) time(NULL));
// 	for (size_t i = 0; i < _n; i++)
// 	{
// 		_numbers.push_back(rand());
// 	}
// 	std::cout << "Size : " << _numbers.size() << std::endl;
// }

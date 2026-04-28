#ifndef SPAN_HPP
#define SPAN_HPP
#include <exception>
#include <vector>

class	Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &op);
		~Span();

		void	addNumber(long long number);
		int		shortestSpan();
		int		longestSpan();
		void	addRange(unsigned int start, unsigned int end);
		void	addRangeRand(unsigned int range);


		class	AlreadyFull : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class	Flow : public std::exception
		{
			public:
				const char*	what() const throw();
		};

	private:
		std::vector<int>	_numbers;
		unsigned int		_n;
};

#endif


// template <typename InputIterator>
// 		void addRangeI(InputIterator begin, InputIterator end)
// 		{
// 			if (static_cast<unsigned int>(std::distance(begin, end)) + _numbers.size() > _n)
// 				throw AlreadyFull();
// 			_numbers.insert(_numbers.end(), begin, end);
// 			std::cout << "Size : " << _numbers.size() << std::endl;
// 		}

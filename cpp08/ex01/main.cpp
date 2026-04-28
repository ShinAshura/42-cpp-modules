#include <iostream>
#include "Span.hpp"

int main()
{
	{
		std::cout << "===== 42 main =====" << std::endl;
		try
		{
			Span sp = Span(5);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught : " << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n===== Only one number =====" << std::endl;
		try
		{
			Span sp = Span(5);

			sp.addNumber(6);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught : " << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n===== Full =====" << std::endl;
		try
		{
			Span sp = Span(3);

			sp.addNumber(6);
			sp.addNumber(5);
			sp.addNumber(2);
			sp.addNumber(1);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught : " << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n===== And another (one) test =====" << std::endl;
		try
		{
			Span sp = Span(8);

			sp.addNumber(6);
			sp.addNumber(8);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.addNumber(-11);
			sp.addNumber(-2);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught : " << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n===== Over 9 000 !!! =====" << std::endl;
		try
		{
			Span sp = Span(10000);

			sp.addRange(1, 10000);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught : " << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n===== Over 9 000 !!! 2 =====" << std::endl;
		try
		{
			Span sp = Span(10000);

			sp.addRange(1, 10002);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught : " << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n===== Over 9 000  Rand !!! =====" << std::endl;
		try
		{
			Span sp = Span(10000);

			sp.addRangeRand(10000);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught : " << e.what() << std::endl;
		}
	}


	return 0;
}


// {
// 		std::cout << "\n===== test =====" << std::endl;
// 		try
// 		{
// 			Span sp(10000);

// 			std::vector<int> bigData;
// 			for (int i = 0; i < 10000; ++i)
// 				bigData.push_back(i);

// 			sp.addRangeI(bigData.begin(), bigData.end());

// 			std::cout << sp.shortestSpan() << std::endl;
// 			std::cout << sp.longestSpan() << std::endl;
// 		}
// 		catch (std::exception &e)
// 		{
// 			std::cout << "Exception caught : " << e.what() << std::endl;
// 		}
// 	}

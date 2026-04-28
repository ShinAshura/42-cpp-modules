#include <iostream>
#include "Array.hpp"

int	main()
{
	Array<int> numbers(5);
	for (int i = 0; i < 5; i++)
		numbers[i] = (i + 1) * 2;

	for (int i = 0; i < 5; i++)
		std::cout << numbers[i] << std::endl;
	
	{
		std::cout << "\n===== Scope numbers array size =====" << std::endl;
		std::cout << "size : " << numbers.size() << std::endl;
	}
	{
		std::cout << "\n===== Scope out of bound =====" << std::endl;
		try
		{
			std::cout << numbers[5];
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught : " << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n===== Scope deep copy =====" << std::endl;
		Array<int> tmp = numbers;
		Array<int> test(tmp);

		int	value = numbers[0] + 1;
		tmp[0] = 42;
		if (numbers[0] == value)
		{
			std::cerr << "shallow copy" << std::endl;
			return 1;
		}
		std::cout << "numbers[0] : " << numbers[0] << std::endl;
		std::cout << "tmp[0] : " << tmp[0] << std::endl;
		std::cout << "test[0] : " << test[0] << std::endl;
	}

	////////////////////////////////////////////////////////////////
	{
		std::cout << "\n===== Scope arrays =====" << std::endl;
		Array<std::string> strings(4);
		strings[0] = "this";
		strings[1] = "is";
		strings[2] = "a";
		strings[3] = "test";

		for (int i = 0; i < 4; i++)
			std::cout << strings[i] << std::endl;
	
		{
			std::cout << "\n===== Scope string array size =====" << std::endl;
			std::cout << "strings array size : " << strings.size() << std::endl;
		}
		std::cout << "===== out of bound array =====" << std::endl;
		try
		{
			// std::cout << strings[-1] << std::endl;
			std::cout << strings[4] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught : " << e.what() << std::endl;
		}
	
	}

	{
		std::cout << "\n===== Scope empty =====" << std::endl;
		Array<int> empty;
		std::cout << empty.size() << std::endl;
		try
		{
			std::cout << empty[0] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught : " << e.what() << std::endl;
		}
	}

	return 0;
}
#include <iostream>
#include <string>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main()
{
	Base	*copyPtr = Base::generate();
	if (!copyPtr)
	{
		std::cerr << "Generated null ptr" << std::endl;
		return (1);
	}
	identify(copyPtr);
	
	///////////////////////////////////////
	
	Base	&copyRef = *copyPtr;
	identify(copyRef);


	delete copyPtr;


	return (0);
}

// {
// 		for (int i = 0; i < 10; ++i)
// 		{
// 			std::cout << "Test #" << i + 1 << std::endl;

// 			Base* obj = Base::generate();

// 			if (!obj)
// 			{
// 				std::cerr << "Failed to generate object (null pointer)" << std::endl;
// 				continue;
// 			}

// 			std::cout << "identify(Base*): ";
// 			identify(obj);

// 			std::cout << "identify(Base&): ";
// 			identify(*obj);

// 			std::cout << "---------------------------" << std::endl;

// 			delete obj;
// 		}
// 	}

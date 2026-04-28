#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include "easyfind.hpp"

int	main()
{
	std::list<int>		lst;
	lst.push_back(12);
	lst.push_back(2);
	lst.push_back(6);
	lst.push_back(42);
	lst.push_back(30);
	lst.push_back(6);
	
	std::vector<int>	vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(13);
	vec.push_back(37);
	vec.push_back(107);

	std::deque<int>		deq;
	deq.push_back(113);
	deq.push_back(137);
	deq.push_back(1013);
	deq.push_back(1079);
	deq.push_back(1237);

	try
	{
		std::list<int>::iterator	itL = easyfind(lst, 6);
		int							index = std::distance(lst.begin(), itL);
		std::cout << "Found " << *itL << " at index " << index << std::endl;

		std::vector<int>::iterator	itV = easyfind(vec, 13);
		std::cout << "Vector : " << *itV << " at index " << std::distance(vec.begin(), itV) << std::endl;
		// std::cout << "Vector : " << *easyfind(vec, 13) << std::endl;

		std::deque<int>::iterator	itD = easyfind(deq, 137);
		std::cout << "Deque : " << *itD << " at index " << std::distance(deq.begin(), itD) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught : " << e.what() << std::endl;
	}

	std::set<int>	s;

	s.insert(13);
	s.insert(42);
	s.insert(7);
	s.insert(37);

	try
	{
		std::set<int>::iterator		itS = easyfind(s, 42);
		std::cout << "Set : " << *itS << " at index " << std::distance(s.begin(), itS) << std::endl;
	}

	catch (std::exception &e)
	{
		std::cerr << "Exception caught " << e.what() << std::endl;
	}

	
	return 0;
}

// {
// 	std::list<int> lst2;
// 	lst2.push_back(10);
// 	lst2.push_back(20);

// 	// Non-const usage
// 	std::list<int>::iterator it = easyfind(lst2, 20);
// 	std::cout << *it << std::endl;

// 	// Fill a list, then make it const
// 	std::list<int> temp;
// 	temp.push_back(10);
// 	temp.push_back(20);
// 	const std::list<int> clst(temp);

// 	// Const usage
// 	std::list<int>::const_iterator cit = easyfind(clst, 10);
// 	std::cout << *cit << std::endl;
// }

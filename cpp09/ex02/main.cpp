#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"

static bool	isValidArg(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error : empty arguments, please give a valid sequence of positive integer" << std::endl;
		return false;
	}
	for (int i = 1; i < ac; i++)
	{
		if (std::atoll(av[i]) > 2147483647)
		{
			std::cerr << "Error: overflow of int" << std::endl;
			return false;
		}
		else if (std::atoll(av[i]) < 0)
		{
			std::cerr << "Error: negative number (please only use positive integer)" << std::endl;
			return false;
		}
	}

	for (int i = 1; i < ac - 1; i++)
	{
		for (int j = i + 1; j < ac; j++)
		{
			if (std::atoi(av[i]) == std::atoi(av[j]))
			{
				std::cerr << "Error: duplicate detected" << std::endl;
				return false;
			}
		}
	}

	return true;
}

int	main(int ac, char **av)
{
	std::vector<int>	rvector;
	std::deque<int>		rdeku;
	std::list<int>		rlist;
	// std::vector<int>	vector;
	// std::deque<int>		deku;
	// std::list<int>		list;

	if (isValidArg(ac, av) == false)
		return 1;

	std::cout << "Before:   ";
	for (int i = 1; i < ac; i++)
	{
		std::cout << av[i] << " ";
		rvector.push_back(std::atoi(av[i]));
		rdeku.push_back(std::atoi(av[i]));
		rlist.push_back(std::atoi(av[i]));
		// vector.push_back(std::atoi(av[i]));
		// deku.push_back(std::atoi(av[i]));
		// list.push_back(std::atoi(av[i]));
	}
	std::cout << std::endl;


	// std::cout << "Before:   ";
	// std::vector<int>::iterator vite = rvector.end();
	// for (std::vector<int>::iterator it = rvector.begin(); it != vite; it++)
	// {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;
	clock_t	rvstart = clock();
	rvector = PmergeMe::rMergeInsertSort(rvector);
	clock_t	rvend = clock();
	double rvectorElapsed = static_cast<double>(rvend - rvstart) * 1e6 / CLOCKS_PER_SEC;
	std::cout << "After:    ";
	std::vector<int>::iterator rvite = rvector.end();
	for (std::vector<int>::iterator it = rvector.begin(); it != rvite; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::rvector : " << rvectorElapsed << " μs" << std::endl;

	//==========================================================================

	// // std::cout << "Before:   ";
	// // std::deque<int>::iterator rdite = rdeku.end();
	// // for (std::deque<int>::iterator it = rdeku.begin(); it != rdite; it++)
	// // {
	// // 	std::cout << *it << " ";
	// // }
	// // std::cout << std::endl;
	// clock_t	rdstart = clock();
	// rdeku = PmergeMe::rMergeInsertSort(rdeku);
	// clock_t	rdend = clock();
	// double rdequeElapsed = static_cast<double>(rdend - rdstart) * 1e6 / CLOCKS_PER_SEC;
	// // std::cout << "After:    ";
	// // std::deque<int>::iterator rdite2 = rdeku.end();
	// // for (std::deque<int>::iterator it = rdeku.begin(); it != rdite2; it++)
	// // {
	// // 	std::cout << *it << " ";
	// // }
	// // std::cout << std::endl;
	// std::cout << "Time to process a range of " << ac - 1 << " elements with std::rdeque  : " << rdequeElapsed << " μs" << std::endl;

	//========================================================================

	// std::cout << "Before:   ";
	// std::list<int>::iterator ite = rlist.end();
	// for (std::list<int>::iterator it = rlist.begin(); it != ite; it++)
	// {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;
	clock_t	rlstart = clock();
	// std::cout << "\n\n =====  LIST ====" << std::endl;
	rlist = PmergeMe::rMergeInsertSort(rlist);
	clock_t	rlend = clock();
	double	rlistElapsed = static_cast<double>(rlend - rlstart) * 1e6 / CLOCKS_PER_SEC;
	// std::cout << "After:    ";
	// std::list<int>::iterator ite2 = rlist.end();
	// for (std::list<int>::iterator it = rlist.begin(); it != ite2; it++)
	// {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::rlist   : " << rlistElapsed << " μs" << std::endl;



	//========================================================================
	//========================================================================
	//========================================================================



	// // std::cout << "Before:   ";
	// // std::vector<int>::iterator vite = vector.end();
	// // for (std::vector<int>::iterator it = vector.begin(); it != vite; it++)
	// // {
	// // 	std::cout << *it << " ";
	// // }
	// // std::cout << std::endl;
	// clock_t	vstart = clock();
	// vector = PmergeMe::mergeInsertSort(vector);
	// clock_t	vend = clock();
	// double vectorElapsed = static_cast<double>(vend - vstart) * 1e6 / CLOCKS_PER_SEC;
	// // std::cout << "After:    ";
	// // std::vector<int>::iterator vite2 = vector.end();
	// // for (std::vector<int>::iterator it = vector.begin(); it != vite2; it++)
	// // {
	// // 	std::cout << *it << " ";
	// // }
	// // std::cout << std::endl;
	// std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << vectorElapsed << " μs" << std::endl;



	// // std::cout << "Before:   ";
	// // std::deque<int>::iterator dite = deku.end();
	// // for (std::deque<int>::iterator it = deku.begin(); it != dite; it++)
	// // {
	// // 	std::cout << *it << " ";
	// // }
	// // std::cout << std::endl;
	// clock_t	dstart = clock();
	// deku = PmergeMe::mergeInsertSort(deku);
	// clock_t	dend = clock();
	// double dequeElapsed = static_cast<double>(dend - dstart) * 1e6 / CLOCKS_PER_SEC;
	// // std::cout << "After:    ";
	// // std::deque<int>::iterator dite2 = deku.end();
	// // for (std::deque<int>::iterator it = deku.begin(); it != dite2; it++)
	// // {
	// // 	std::cout << *it << " ";
	// // }
	// // std::cout << std::endl;
	// std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque  : " << dequeElapsed << " μs" << std::endl;



	// // std::cout << "Before:   ";
	// // std::list<int>::iterator ite = list.end();
	// // for (std::list<int>::iterator it = list.begin(); it != ite; it++)
	// // {
	// // 	std::cout << *it << " ";
	// // }
	// // std::cout << std::endl;
	// clock_t	lstart = clock();
	// // std::cout << "\n\n =====  LIST ====" << std::endl;
	// list = PmergeMe::mergeInsertSort(list);
	// clock_t	lend = clock();
	// double	listElapsed = static_cast<double>(lend - lstart) * 1e6 / CLOCKS_PER_SEC;
	// // std::cout << "After:    ";
	// // std::list<int>::iterator ite2 = list.end();
	// // for (std::list<int>::iterator it = list.begin(); it != ite2; it++)
	// // {
	// // 	std::cout << *it << " ";
	// // }
	// // std::cout << std::endl;
	// std::cout << "Time to process a range of " << ac - 1 << " elements with std::list   : " << listElapsed << " μs" << std::endl;


	return 0;
}

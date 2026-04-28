#include "PmergeMe.hpp"
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &op)
{
	(void)op;
	return *this;
}

PmergeMe::~PmergeMe() {}


void	binaryInsert(std::vector<int> &sorted, int value)
{
	std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(pos, value);
}


std::vector<int>	PmergeMe::rMergeInsertSort(std::vector<int> &vec)
{
	size_t	size = vec.size();
	if (size <= 1)
		return vec;

	std::vector<int>	larger;
	std::vector<int>	smaller;
	int					leftover = -1;
	bool				hasLeftover = false;

	size_t	i = 0;
	while (i + 1 < size)
	{
		int a = vec[i];
		int	b = vec[i + 1];

		if (a > b)
		{
			larger.push_back(a);
			smaller.push_back(b);
		}
		else
		{
			larger.push_back(b);
			smaller.push_back(a);
		}
		i = i + 2;
	}

	if (i < size)
	{
		leftover = vec[i];
		hasLeftover = true;
	}

	std::vector<int>	sortedMain = rMergeInsertSort(larger);

	for (size_t j = 0; j < smaller.size(); j++)
	{
		binaryInsert(sortedMain, smaller[j]);
	}

	if (hasLeftover)
		binaryInsert(sortedMain, leftover);

	return sortedMain;
}



void	binaryInsert(std::list<int> &sorted, int value)
{
	std::list<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(pos, value);
}


std::list<int>	PmergeMe::rMergeInsertSort(std::list<int> &list)
{
	if (list.empty())
		return std::list<int>();

	std::list<int>	larger;
	std::list<int>	smaller;
	int				leftover = -1;
	bool			hasLeftover = false;

	std::list<int>::iterator it = list.begin();
	while (it != list.end())
	{
		std::list<int>::iterator	next = it;
		next++;

		if (next == list.end())
		{
			leftover = *it;
			hasLeftover = true;
			break;
		}

		int a = *it;
		int b = *next;

		if (a > b)
		{
			larger.push_back(a);
			smaller.push_back(b);
		}
		else
		{
			larger.push_back(b);
			smaller.push_back(a);
		}
		next++;
		it = next;
	}

	std::list<int>	sortedMain = rMergeInsertSort(larger);
	
	for (std::list<int>::iterator rit = smaller.begin(); rit != smaller.end(); rit++)
	{
		binaryInsert(sortedMain, *rit);
	}

	if (hasLeftover)
		binaryInsert(sortedMain, leftover);

	return sortedMain;
}


//===========================================================================
//===========================================================================
//===========================================================================


// std::vector<int>	PmergeMe::mergeInsertSort(std::vector<int> &vec)
// {
// 	if (vec.empty())
// 		return std::vector<int>();

// 	std::vector<int>	main;
// 	std::vector<int>	remainder;

// 	size_t	i = 0;
// 	while (i + 1 < vec.size())
// 	{
// 		int a = vec[i];
// 		int b = vec[i + 1];
// 		if (a > b)
// 		{
// 			main.push_back(a);
// 			remainder.push_back(b);
// 		}
// 		else
// 		{
// 			main.push_back(b);
// 			remainder.push_back(a);
// 		}
// 		i = i + 2;
// 	}

// 	int		leftover = -1;
// 	bool	hasLeftover = false;
// 	if (i < vec.size())
// 	{
// 		leftover = vec[i];
// 		hasLeftover = true;
// 	}

// 	std::sort(main.begin(), main.end());

// 	for (size_t j = 0; j < remainder.size(); j++)
// 	{
// 		binaryInsert(main, remainder[j]);
// 	}

// 	if (hasLeftover)
// 		binaryInsert(main, leftover);

// 	return main;
// }


// std::list<int>	PmergeMe::mergeInsertSort(std::list<int> &list)
// {
// 	if (list.empty())
// 		return std::list<int>();

// 	std::list<int>	main;
// 	std::list<int>	remainder;
// 	int				leftover = -1;
// 	bool			hasLeftover = false;

// 	std::list<int>::iterator it = list.begin();
// 	while (it != list.end())
// 	{
// 		std::list<int>::iterator	next = it;
// 		next++;

// 		if (next == list.end())
// 		{
// 			leftover = *it;
// 			hasLeftover = true;
// 			break;
// 		}

// 		int a = *it;
// 		int b = *next;

// 		if (a > b)
// 		{
// 			main.push_back(a);
// 			remainder.push_back(b);
// 		}
// 		else
// 		{
// 			main.push_back(b);
// 			remainder.push_back(a);
// 		}
// 		next++;
// 		it = next;
// 	}

// 	main.sort();
	
// 	for (std::list<int>::iterator rit = remainder.begin(); rit != remainder.end(); rit++)
// 	{
// 		binaryInsert(main, *rit);
// 	}

// 	if (hasLeftover)
// 		binaryInsert(main, leftover);

// 	return main;
// }





// void	binaryInsert(std::deque<int> &sorted, int value)
// {
// 	std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
// 	sorted.insert(pos, value);
// }

// std::deque<int>	PmergeMe::mergeInsertSort(std::deque<int> &deku)
// {
// 	if (deku.empty())
// 		return std::deque<int>();

// 	std::deque<int>	main;
// 	std::deque<int>	remainder;

// 	size_t	i = 0;
// 	while (i + 1 < deku.size())
// 	{
// 		int	a = deku[i];
// 		int b = deku[i + 1];

// 		if (a > b)
// 		{
// 			main.push_back(a);
// 			remainder.push_back(b);
// 		}
// 		else
// 		{
// 			main.push_back(b);
// 			remainder.push_back(a);
// 		}
// 		i = i + 2;
// 	}

// 	int	leftover = -1;
// 	bool	hasLeftover = false;
// 	if (i < deku.size())
// 	{
// 		leftover = deku[i];
// 		hasLeftover = true;
// 	}

// 	std::sort(main.begin(), main.end());

// 	for (size_t j = 0; j < remainder.size(); j++)
// 	{
// 		binaryInsert(main, remainder[j]);
// 	}

// 	if (hasLeftover)
// 		binaryInsert(main, leftover);

// 	return main;
// }

// std::deque<int>	PmergeMe::rMergeInsertSort(std::deque<int> &deku)
// {
// 	if (deku.empty())
// 		return std::deque<int>();

// 	std::deque<int>	larger;
// 	std::deque<int>	smaller;

// 	size_t	i = 0;
// 	while (i + 1 < deku.size())
// 	{
// 		int	a = deku[i];
// 		int b = deku[i + 1];

// 		if (a > b)
// 		{
// 			larger.push_back(a);
// 			smaller.push_back(b);
// 		}
// 		else
// 		{
// 			larger.push_back(b);
// 			smaller.push_back(a);
// 		}
// 		i = i + 2;
// 	}

// 	int	leftover = -1;
// 	bool	hasLeftover = false;
// 	if (i < deku.size())
// 	{
// 		leftover = deku[i];
// 		hasLeftover = true;
// 	}

// 	std::deque<int>	sortedMain = rMergeInsertSort(larger);

// 	for (size_t j = 0; j < smaller.size(); j++)
// 	{
// 		binaryInsert(sortedMain, smaller[j]);
// 	}

// 	if (hasLeftover)
// 		binaryInsert(sortedMain, leftover);

// 	return sortedMain;
// }

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <list>
#include <deque>

class	PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &op);
		~PmergeMe();

		static std::vector<int>	rMergeInsertSort(std::vector<int> &vec);
		static std::list<int>	rMergeInsertSort(std::list<int> &list);
		// static std::deque<int>	rMergeInsertSort(std::deque<int> &deku);
		// static std::vector<int>	mergeInsertSort(std::vector<int> &vec);
		// static std::list<int>	mergeInsertSort(std::list<int> &list);
		// static std::deque<int>	mergeInsertSort(std::deque<int> &deku);

};

#endif

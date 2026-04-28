#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

int main ()
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "Stack top : " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "Size : " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}


	{
		std::cout << "\n===== LIST =====" << std::endl;
		std::list<int> lst;

		lst.push_back(5);
		lst.push_back(17);

		std::cout << "Lst back : " << lst.back() << std::endl;

		lst.pop_back();

		std::cout << "Size : " << lst.size() << std::endl;

		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		//[...]
		lst.push_back(0);

		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	{
		std::cout << "\n===== primestack =====" << std::endl;
		MutantStack<int>	mprimestack;

		mprimestack.push(2);
		mprimestack.push(3);
		mprimestack.push(5);
		mprimestack.push(7);
		mprimestack.push(11);
		mprimestack.push(13);
		mprimestack.push(17);
		mprimestack.push(23);

		std::cout << "Size : " << mprimestack.size() << std::endl;

		MutantStack<int>::iterator it = mprimestack.begin();
		MutantStack<int>::iterator ite = mprimestack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			it++;
		}
	}

	{
		std::cout << "\n===== primestack reverse print=====" << std::endl;
		MutantStack<int>	mprimestack;

		mprimestack.push(2);
		mprimestack.push(3);
		mprimestack.push(5);
		mprimestack.push(7);
		mprimestack.push(11);
		mprimestack.push(13);
		mprimestack.push(17);
		mprimestack.push(23);

		std::cout << "Size : " << mprimestack.size() << std::endl;

		MutantStack<int>::reverse_iterator rit = mprimestack.rbegin();
		MutantStack<int>::reverse_iterator rite = mprimestack.rend();
		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			rit++;
		}


		// std::cout << "===== copy ====" << std::endl;
		// MutantStack<int>	mprimestackcopy(mprimestack);

		// MutantStack<int>::iterator it = mprimestackcopy.begin();
		// MutantStack<int>::iterator ite = mprimestackcopy.end();
		// while (it != ite)
		// {
		// 	std::cout << *it << std::endl;
		// 	it++;
		// }


		// std::cout << "==== op copy ====" << std::endl;
		// MutantStack<int>	mprimestackop(mprimestack);

		// MutantStack<int>::iterator opit = mprimestackop.begin();
		// MutantStack<int>::iterator opite = mprimestackop.end();
		// while (opit != opite)
		// {
		// 	std::cout << *opit << std::endl;
		// 	opit++;
		// }
	}

	return 0;
}

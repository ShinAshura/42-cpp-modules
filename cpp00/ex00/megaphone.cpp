#include <iostream>

int main(int ac, char **av) {
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i <= ac - 1; i++)
			for (int j = 0; av[i][j]; j++)
				std::cout << (char)toupper(av[i][j]);
		std::cout << std::endl;
	}
    return (0);
}
// std::cout << "Hello World\n";
// std::cout << "I like pizza !" << std::endl;
// std::cout << "It's really good" << '\n';

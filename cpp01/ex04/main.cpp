#include <iostream>
#include <fstream>
#include <cstring>

std::string	ft_my_replace(std::string str, char *s1, char *s2)
{
	std::string	newLine;
	// const char*	s2safe = (s2 ? s2 : "");

	if (!s1 || !s1[0])
		return (str);
	size_t len1 = std::strlen(s1);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i + len1 <= str.length() && std::strncmp(&str[i], s1, len1) == 0)
		{
			newLine = newLine + s2;
			i = i + len1 - 1;
		}
		else
			newLine = newLine + str[i];
	}
	return (newLine);
}

// for (size_t i = 0; i < str.length(); i++)
// 	{
// 		size_t	tmp_i = i;
// 		if (str[i] == s1[0])
// 		{
// 			int	j = 0;
// 			while (str[i] == s1[j] && str[i] != 0)
// 			{
// 				i++;
// 				j++;
// 			}
// 			if (s1[j] == 0)
// 			{
// 				for (int k = 0; s2[k]; k++)
// 					newLine = newLine + s2[k];
// 				// newLine = newLine + s2;
// 				i--;
// 			}
// 			else
// 			{
// 				i = tmp_i;
// 				newLine = newLine + str[i];
// 			}
// 		}
// 		else
// 			newLine = newLine + str[i];
// 	}


int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Please run the program like this : ./sed <filename> <string s1> <string s2>" << std::endl;
		return (0);
	}
	if (!av[2][0] || !av[3][0])
	{
		std::cout << "Please run the program with <string s1> <string s2> not empty : ./sed <filename> <string s1> <string s2>" << std::endl;
		return (0);
	}

	std::string		line;
	std::ifstream	ifs(av[1]);
	if (!ifs.is_open())
	{
		std::cerr << "Error ifs" << std::endl;
		return (1);
	}
	std::string		filename = std::string(av[1]) + ".replace";
	std::ofstream	ofs(filename.c_str());

	if (!ofs.is_open())
	{
		std::cerr << "Error ofs" << std::endl;
		return (1);
	}
							// if (!ifs.is_open() || !ofs.is_open())
							// {
							// 	std::cerr << "Error opening files" << std::endl;
							// 	return (1);
							// }
	while (std::getline(ifs, line))
	{
		line = ft_my_replace(line, av[2], av[3]);
		// std::cout << "line : " << line << std::endl;
		ofs << line << std::endl;
	}
	ofs.close();
	return (0);
}

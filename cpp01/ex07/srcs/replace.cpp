#include "../include/replace.hpp"

replace::replace(std::string file, std::string argv1, std::string argv2)
: filename(file), s1(argv1), s2(argv2)
{
}

replace::~replace()
{
}

int		replace::check(void)
{
	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cout << "Error at least one argument is empty." << std::endl;
		return (1);
	}
	return (0);
}

int		replace::replace_program(void)
{
	std::ifstream		input;
	std::stringstream	ret;
	std::string			tmp;
	size_t				c = 0;

	if (check() == 1)
		return (1);
	input.open(filename);
	if (input.is_open())
	{
		while (std::getline(input, tmp))
		{
			if (c == tmp.npos)
				ret << std::endl;
			while ((c = tmp.find(s1)) != tmp.npos)
				tmp.replace(c, s1.length(), s2);
			ret << tmp;
		}
		input.close();
		return (write_replace(ret.str()));
	}
	std::cout << "Error impossible to open your file." << std::endl;
	return (1);
}

int			replace::write_replace(std::string ret)
{
	std::ofstream		output;

	output.open(filename += ".replace");
	if (output.is_open())
	{
		output << ret;
		output.close();
		return (0);
	}
	std::cout << "Error impossible to creat your filename.replace." << std::endl;
	return (1);
}

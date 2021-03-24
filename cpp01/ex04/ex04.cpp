#include <iostream>

int			main(void)
{
	std::string		base = "HI THIS IS BRAIN";
	std::string		*pointeur = &base;
	std::string		&reference = base;

	std::cout << *pointeur << std::endl << reference << std::endl;
	return (0);
}

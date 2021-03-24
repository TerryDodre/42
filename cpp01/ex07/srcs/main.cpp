#include "../include/replace.hpp"

int		main(int argc, char **argv)
{
	if (argc != 4)
		std::cout << "./replace need 3 arguments : \
./replace file s1 s2" << std::endl;
	else
	{
		replace		rp(argv[1], argv[2], argv[3]);
		return (rp.replace_program());
	}
	return (1);
}

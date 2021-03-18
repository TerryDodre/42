#include <iostream>

void		ft_toupper(char *str)
{
	int		i = 0;

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	std::cout << str;
}

int			main(int argc, char **argv)
{
	int		i = 1;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (argv[i])
			ft_toupper(argv[i++]);
		std::cout << std::endl;
	}
	return (0);
}

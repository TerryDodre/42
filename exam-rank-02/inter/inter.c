#include <unistd.h>

int		main(int argc, char **argv)
{
	int	i = 0;
	int	j = 0;
	int	x = 0;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			x = 0;
			j = 0;
			while (argv[1][i] != argv[1][j] && j < i)
				j++;
			while (argv[1][i] != argv[2][x] && argv[2][x])
				x++;
			if (argv[2][x] == argv[1][i] && i == j)
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
#include <unistd.h>

int		main(int argc, char **argv)
{
	int		i = 0;
	int		j = 0;
	int		x = 0;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			j = 0;
			while (argv[1][j] != argv[1][i] && j < i)
				j++;
			if (j == i)
				write(1, &argv[1][i], 1);
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			j = 0;
			x = 0;
			while (argv[2][j] != argv[2][i] && j < i)
				j++;
			while (argv[2][i] != argv[1][x] && argv[1][x])
				x++;
			if (j == i && argv[1][x] == '\0')
				write(1, &argv[2][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
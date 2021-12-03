#include <unistd.h>

int ft_check(char *av, char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (av[i] == c)
			return (0);
		i++;
	}
	return(1);
}

int	main(int ac, char **av)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (ac != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	while (av[1][a])
	{
		b = 0;
		while (av[2][b])
		{
			if (av[1][a] == av[2][b])
			{
				if (ft_check(av[1], av[1][a], a) == 1)
				{
					write (1, &av[1][a], 1);
					break;
				}
			}
			b++;
		}
		a++;
	}
	write (1, "\n", 1);
	return (0);
}


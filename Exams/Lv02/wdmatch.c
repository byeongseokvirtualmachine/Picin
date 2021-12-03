#include <unistd.h>

int	main(int ac, char **av)
{
	int	a;
	int	b;
	int	len;

	a = 0;
	b = 0;
	len = 0;
	if (ac == 3)
	{
		while (av[2][b])
		{
			if (av[1][a] == av[2][b])
				a++;
			b++;
		}
		while (av[1][len])
			len++;
		if (a == len)
		{
			len = 0;
			while (av[1][len])
			{
				write (1, &av[1][len], 1);
				len++;
			}
		}
	}
	write (1, "\n", 1);
	return (0);
}

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_check(char *str1, int c)
{
	int	i;

	i = 0;
	while(i < c)
	{
		if (str1[c] == str1[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check2(char *str1, char *str2, int c)
{
	int	i;

	i = 0;
	while(str1[i])
	{
		if (str2[c] == str1[i])
			return (0);
		i++;
	}
	i = 0;
	while(i < c)
	{
		if (str2[c] == str2[i])
			return(0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (ac == 3)
	{
		while (av[1][a])
		{
			if (ft_check(av[1], a) == 1)
			{
				ft_putchar (av[1][a]);
			}
			a++;
		}
		while (av[2][b])
		{
			if (ft_check2(av[1], av[2], b) == 1)
			{
				ft_putchar (av[2][b]);
			}
			b++;
		}
	}
	ft_putchar ('\n');
}

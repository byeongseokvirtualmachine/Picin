#include <unistd.h>

int	ft_atoi(char *nbr)
{
	int	r;
	int	i;

	r = 0;
	i = 0;
	while (nbr[i])
	{
		r = r * 10 + (nbr[i] - '0');
		i++;
	}
	return (r);
}

int	ft_next(int i)
{
	int	j;

	while (j < i)
	{
		j = 2;
		while (j < i / 2)
		{
			if (i % j != 0)
				i++;
			else
				break;
			if ( j == i / 2)
				return (i);
		}
		j++;
	}
	return (0);
}

void	ft_putnbr(int nbr)
{
	long long	r;
	int		i;

	r = nbr;
	if (r > 9)
	{
		ft_putnbr(r / 10);
		i = r % 10 + '0';
		write(1, &i, 1);
	}
	else
	{
		r = r + '0';
		write(1, &r, 1);
	}
}
		
void	ft_fprime(char *nbr)
{
	int	r;
	int	i;

	r = ft_atoi(nbr);
	i = 2;
	while (i <= r)
	{
		if (r % i == 0)
		{
			r = r / i;
			ft_putnbr(i);
			if (r != 1)
				write(1, "*", 1);
			else if (r == 1)
				write(1, "\n", 1);
		}
		else
			i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_fprime(av[1]);
	return (0);
}

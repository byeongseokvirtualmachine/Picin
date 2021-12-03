#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
}

int	ft_atoi(char* str)
{
	int	i;
	int	result;
	int	minus;

	i = 0;
	minus = 1;
	result = 0;
	while ((str[i] >= 0 && str[i] <= 32) || str[i] == 127)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result = result + str[i] - '0';
		i++;
	}
	return (result * minus);
}

int	ft_prime(int nb)
{
	int	i;
	int	result;

	i = 2;
	result = 0;
	if (nb == 2)
		return(2);
	else
	{
		while (i < nb)
		{
			if (nb % i == 0)
				break;
			else if (i == nb - 1)
				result = result + i + 1;
			i++;
		}
	}
	return (result);
}

int	ft_sum(int nb)
{
	int	i;
	int	result;

	result = 0;
	i = 2;
	if (nb <= 0)
		return (0);
	else if (nb == 2)
		return (2);
	else
	{
		while (i <= nb)
		{
			result = result + ft_prime(i);
			i++;
		}
	}
	return (result);
}

#include <stdio.h>
int	main(int ac, char** av)
{
	if (ac != 2)
		write (1, "0", 1);
	else
	ft_putnbr(ft_sum(ft_atoi(av[1])));
	write(1, "\n", 1);
	ft_putnbr(ft_atoi(av[1]));
	write (1, "\n", 1);
	printf("%d\n", ft_atoi(av[1]));
	return (0);
}

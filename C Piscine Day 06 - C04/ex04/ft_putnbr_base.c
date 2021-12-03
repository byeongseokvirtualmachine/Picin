#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_check_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (base == 0 || ft_strlen(base) <= 1)
		return (1);
	while (base[i])
	{
		if (base[i] == 43 || base[i] == 45 || base[i] <= 32 || base[i] == 127)
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	result;
	int		base_n;

	if (ft_check_base(base))
		return ;
	result = nbr;
	base_n = ft_strlen(base);
	if (result < 0)
	{
		result = -result;
		ft_putchar('-');
	}
	if (result < base_n)
	{
		ft_putchar(base[result]);
	}
	else
	{
		ft_putnbr_base(result / base_n, base);
		ft_putnbr_base(result % base_n, base);
	}
}

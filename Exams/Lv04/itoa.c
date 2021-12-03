#include <unistd.h>
#include <stdlib.h>

char *ft_itoa(int r)
{
	int	i;
	int	nbr;
	char	*str;

	i = 0;
	nbr = r;
	while (r > 0)
	{
		r = r / 10;
		i++;
	}
	str = (char *)malloc(sizeof(char) * i + 1);
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	return (str);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(void)
{
	int	nbr = 12345;

	ft_putstr(ft_itoa(nbr));
	return (0);
}

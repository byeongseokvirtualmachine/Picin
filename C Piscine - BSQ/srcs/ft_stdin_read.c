#include "ft.h"

#define F_SIZE 1000

char	*ft_charcat(char *dest, char src)
{
	char	*pdst;

	pdst = dest;
	while (*pdst != '\0')
		pdst++;
	*pdst = src;
	pdst++;
	*pdst = '\0';
	return (dest);
}

int	ft_artoi(char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\n')
		i++;
	while (j < i - 3 && str[j] >= '0' && str[j] <= '9')
	{
		k = k * 10 + (str[j] - '0');
		j++;
	}
	return (k);
}

void	ft_stdin_read(char *buf)
{
	char	c;
	int		i;
	int		j;

	c = 0;
	while (c != '\n')
	{
		read(0, &c, 1);
		ft_charcat(buf, c);
	}
	i = 0;
	j = ft_artoi(buf);
	while (i < j)
	{
		read(0, &c, 1);
		ft_charcat(buf, c);
		if (c == '\n')
			i++;
	}
}

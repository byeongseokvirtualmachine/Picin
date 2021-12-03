#include <stdlib.h>

int	ft_skip_space(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == 43 || base[i] == 45 || base[i] <= 32 || base[i] == 127)
			return (-1);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (-1);
			j++;
		}
		i++;
	}
	if (base == 0 || i <= 1)
		return (-1);
	return (i);
}

int	ft_check_nbr(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_new_base(long r, char *base_to, int sign)
{
	long	i;
	long	l;
	char	*str;

	l = 0;
	i = r;
	while (i > 0 || l == 0)
	{
		i = i / ft_check_base(base_to);
		l++;
	}
	str = (char *)malloc(sizeof(char) * (l + 2));
	if (str == NULL)
		return (NULL);
	if (sign == -1 && r > 0)
		i = 1;
	str[0] = '-';
	str[l + i] = '\0';
	while (l > 0)
	{
		str[l + i - 1] = base_to[r % ft_check_base(base_to)];
		r = r / ft_check_base(base_to);
		l--;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		sign;
	long	r;

	if (ft_check_base(base_from) < 0 || ft_check_base(base_to) < 0)
		return (NULL);
	i = ft_skip_space(nbr);
	sign = 1;
	r = 0;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_check_nbr(nbr[i], base_from))
	{
		r = r * ft_check_base(base_from) + ft_check_nbr(nbr[i], base_from) - 1;
		i++;
	}
	return (ft_new_base(r, base_to, sign));
}

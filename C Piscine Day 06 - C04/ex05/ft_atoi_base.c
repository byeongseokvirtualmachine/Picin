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

int	ft_skip_space(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
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

int	ft_check_number(char c, char *base)
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

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	long	r;
	int		base_n;

	i = ft_skip_space(str);
	sign = 1;
	r = 0;
	base_n = ft_strlen(base);
	if (ft_check_base(base))
		return (0);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_check_number(str[i], base))
	{
		r = r * base_n + (ft_check_number(str[i], base) - 1);
		i++;
	}
	return (sign * r);
}

int	ft_skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] <= 32)
	{
		i++;
	}
	return (i);
}

int	ft_check_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	r;

	sign = 1;
	i = ft_skip_space(str);
	r = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign = -sign;
		}
		i++;
	}
	while (ft_check_number(str[i]))
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (sign * r);
}

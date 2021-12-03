int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (str[++i] == '\0')
			{
				return (1);
			}
		}
		else
		{
			return (0);
		}
	}
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	n;

	i = 0;
	if (str[i] == '\0')
	{
		return (1);
	}
	else
	{
		n = ft_check(str);
		return (n);
	}
}

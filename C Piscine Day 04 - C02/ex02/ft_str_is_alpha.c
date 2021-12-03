int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
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

int	ft_str_is_alpha(char *str)
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

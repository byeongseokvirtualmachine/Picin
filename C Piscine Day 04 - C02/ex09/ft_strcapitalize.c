char	*ft_allcap(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

char	*ft_decap(char *str, int i)
{
	if (str[i + 1] >= 'A' && str[i + 1] <= 'Z')
	{
		str[i + 1] = str[i + 1] + 32;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_allcap(str);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			ft_decap(str, i);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			ft_decap(str, i);
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			ft_decap(str, i);
		}
		i++;
	}
	return (str);
}

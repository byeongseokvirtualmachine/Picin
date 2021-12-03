void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;
	int	ac;

	i = 0;
	j = 0;
	ac = 0;
	while (tab[ac])
		ac++;
	while (j < ac - 1)
	{
		i = 0;
		while (i < ac - j - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				ft_swap(&tab[i], &tab[i + 1]);
			}
			i++;
		}
		j++;
	}
}

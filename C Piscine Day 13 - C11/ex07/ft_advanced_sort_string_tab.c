void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if (cmp(tab[i], tab[i + 1]) > 0)
			{
				ft_swap(&tab[i], &tab[i + 1]);
			}
			i++;
		}
		j++;
	}
}

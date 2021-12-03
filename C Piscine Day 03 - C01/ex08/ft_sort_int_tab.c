void	ft_compare(int *tab, int i)
{
	int	c;

	while (i >= 0)
	{
		if (tab[i] > tab[i + 1])
		{
			c = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = c;
		}
		i--;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		ft_compare(tab, i);
		i++;
	}
}

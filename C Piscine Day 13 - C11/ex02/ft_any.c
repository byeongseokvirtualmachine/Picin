int	ft_any(char **tab, int (*f)(char *))
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (tab[i])
	{
		if (f(tab[i]) != 0)
			r = 1;
		i++;
	}
	return (r);
}

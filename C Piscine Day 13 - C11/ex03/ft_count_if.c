int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			r++;
		i++;
	}
	return (r);
}

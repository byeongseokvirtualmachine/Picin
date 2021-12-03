int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	status;

	i = 0;
	status = 1;
	while (i < length - 1 && status == 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			status = 0;
		i++;
	}
	if (status == 0)
	{
		i = 0;
		status = 1;
		while (i < length - 1)
		{
			if (f(tab[i], tab[i + 1]) < 0)
				status = 0;
			i++;
		}
	}
	if (status == 0)
		return (0);
	return (1);
}

void	sort_int_tab(int *tab, unsigned int size)
{
	int	i;
	int	tmp;
	int	intsize;

	intsize = size;
	i = 0;
	tmp = 0;
	while (i < intsize - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

#include <stdio.h>

int	main(void)
{
	int	tab[10] = {8, 9, 2, 3, 1, 2, 6, 5, 3, 2};
	int	i;

	i = 0;
	while (i < 10)
	{	
		printf("before %d %d\n", i, tab[i]);
		i++;
	}
	sort_int_tab(tab, 10);
	i = 0;
	while (i < 10)
	{
		printf("tab %d %d\n", i, tab[i]);
		i++;
	}
}

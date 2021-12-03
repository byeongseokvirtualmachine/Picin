#include <stdio.h>
#include <stdlib.h>
#include "ft.h"

int	**ft_build_tab(struct s_info *info)
{
	int	**tab;
	int	i;
	int	j;

	tab = (int **)ft_calloc(info->y, sizeof(int *));
	i = 0;
	while (i < info->y)
	{
		tab[i] = (int *)ft_calloc(info->x, sizeof(int));
		j = 0;
		while (j < info->x)
		{
			tab[i][j] = info->tab[i][j];
			j++;
		}
		i++;
	}
	return (tab);
}

void	ft_compute(struct s_info *info, int **tab)
{
	int	a;
	int	b;
	int	min;

	min = 0;
	b = 1;
	while (b < info->y)
	{
		a = 1;
		while (a < info->x)
		{
			if (tab[b][a] != 0)
			{
				min = tab[b - 1][a - 1];
				if (min > tab[b - 1][a])
					min = tab[b - 1][a];
				if (min > tab[b][a - 1])
					min = tab[b][a - 1];
				tab[b][a] = min + 1;
			}
			a++;
		}
		b++;
	}
}

int	**ft_computing(struct s_info *info)
{
	int	**tab;

	tab = ft_build_tab(info);
	ft_compute(info, tab);
	return (tab);
}

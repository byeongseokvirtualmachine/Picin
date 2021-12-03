#include "ft.h"

void	ft_findmax(struct s_info *info, int **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->y)
	{
		j = 0;
		while (j < info->x)
		{
			if (tab[i][j] > info->max)
			{
				info->maxy = i;
				info->maxx = j;
				info->max = tab[i][j];
			}
			j++;
		}
		i++;
	}
}

void	ft_max(struct s_info *info, int **tab)
{
	int	i;
	int	j;

	ft_findmax(info, tab);
	i = info->maxy - info->max + 1;
	while (i <= info->maxy)
	{
		j = info->maxx - info->max + 1;
		while (j <= info->maxx)
		{
			info->tab[i][j] = 2;
			j++;
		}
		i++;
	}
}

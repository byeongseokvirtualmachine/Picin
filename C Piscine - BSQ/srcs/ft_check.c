#include <stdio.h>
#include <stdlib.h>
#include "ft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	**ft_maketab(int col, int row, int i, char *str)
{
	int	j;
	int	l;
	int	**tab;

	j = 0;
	l = 0;
	tab = (int **)malloc(sizeof(int *) * col);
	while (j < col)
	{
		l = 0;
		tab[j] = (int *)malloc(sizeof(int) * row);
		while (l < row - 1)
		{
			if (str[j * row + l + i + 1] == str[i - 3])
				tab[j][l] = 1;
			else if (str[j * row + l + i + 1] == str[i - 2])
				tab[j][l] = 0;
			else
				tab[j][l] = -1;
			l++;
		}
		j++;
	}
	return (tab);
}

void	ft_check(struct s_info *info, char *str)

{
	int	i;
	int	j;

	i = 0;
	info->y = 0;
	info->x = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	info->empty = str[i - 3];
	info->obs = str[i - 2];
	info->full = str[i - 1];
	j = 0;
	while (j < i - 3 && str[j] >= '0' && str[j] <= '9')
	{
		info->y = info->y * 10 + (str[j] - '0');
		j++;
	}
	j = 0;
	if (info->y != 0)
		info->x = (ft_strlen(str) - i - 1) / info->y;
	info->tab = ft_maketab(info->y, info->x, i, str);
	info->x--;
}

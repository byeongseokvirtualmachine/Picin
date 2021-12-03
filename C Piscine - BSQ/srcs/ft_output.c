#include <unistd.h>
#include "ft.h"

void	ft_print_tab(struct s_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->y)
	{
		j = 0;
		while (j < info->x)
		{
			if (info->tab[i][j] == 0)
				write(1, &info->obs, 1);
			else if (info->tab[i][j] == 1)
				write(1, &info->empty, 1);
			else
				write(1, &info->full, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

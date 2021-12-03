#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	*tab;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	tab = (int *) malloc(sizeof(int) * size);
	if (tab == NULL)
	{
		*range = NULL;
		return (-1);
	}
	*range = tab;
	i = 0;
	while (i < size)
	{
		tab[i] = min + i;
		i++;
	}
	return (size);
}

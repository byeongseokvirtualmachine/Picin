#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	i;
	int	*tab;

	i = 0;
	if (min >= max)
		return (NULL);
	size = max - min;
	tab = (int *)malloc(sizeof(int) * size);
	if (tab == NULL)
		return (NULL);
	while (size)
	{
		tab[i] = min + i;
		size--;
		i++;
	}
	return (tab);
}

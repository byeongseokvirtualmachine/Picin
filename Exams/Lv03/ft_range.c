#include <stdio.h>
#include <stdlib.h>

int	ft_size(int start, int end)
{
	if (start > end)
		return (start - end + 1);
	else
		return (end - start + 1);
}

int	*ft_range(int start, int end)
{
	int i;
	int size;
	int *tab;

	i = 0;
	size = ft_size(start, end);
	tab = (int*)malloc(sizeof(int) * size);
	if (tab == NULL)
		return NULL;
	while (start < end)
	{
		tab[i] = start;
		start++;
		i++;
	}
	while (start > end)
	{
		tab[i] = start;
		start--;
		i++;
	}
	tab[i] = start;
	return (tab);
}

int	main(void)
{
	int *array = ft_range(0, 3);
	int i = 0;
	while (i < 4)
	{
		printf("%d\n", array[i]);
		i++;
	}
	free(array);
	return (0);
}

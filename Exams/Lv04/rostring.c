#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void	ft_print(int n, char **tab)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	printf("n %d\n0 %s\n1 %s\n", n, tab[0], tab[1]);
	while(i < n)
	{
		j = 0;
		while(tab[i][j])
		{
//			printf("printij\n");
			write(1, &tab[i][j], 1);
			j++;
		}
//		printf("%d", i);
		i++;
		write(1, " ", 1);
	}
	j = 0;
	while(tab[0][j])
	{
		write(1, &tab[0][j], 1);
		j++;
	}
}

void	ft_split(char *str)
{
	int	i;
	int	j;
	int	k;
	char	**tab;

	i = 0;
	j = 0;
	k = 0;
//	printf("revstrt\n");
	tab = (char **)malloc(sizeof(char *) * 1000);
//	tab[0] = (char *)malloc(sizeof(char) * 1000);
	while (str[k] <= 32 && str[k] != '\0')
		k++;
	while (str[k])
	{
		if (str[k] > 32)
		{
			j = 0;
			tab[i] = (char *)malloc(sizeof(char) * 1000);
			while (str[k] > 32 && str[k] != '\0')
			{
				tab[i][j] = str[k];
				k++;
				j++;
			}
			tab[i][j] = '\0';
			i++;
		}
		else
			k++;
	}
	ft_print(i, tab);
}
		


int	main(int ac, char **av)
{
	if (ac == 2)
		ft_split(av[1]);
	write(1, "\n", 1);
	return (0);
}

#include <stdio.h>
#include <unistd.h>

char	*ft_decap(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		i++;
//		printf("decap\n");
	}
//	printf("%s\n", str);
	return (str);
}

void	print_alpha(int *tab)
{
	int	i;
	int	count;
	char	*alphabet;

	alphabet = "abcdefghijklmnopqrstuvwxyz";
	i = 0;
	count = 0;
	while (i < 26)
	{
		if (tab[i] != 0)
			count++;
		i++;
	}
	i = 0;
	while (i < 26)
	{
//		printf("while i %d %d\n", i, tab[i]);
		if (tab[i] != 0 && count > 1)
		{
			count--;
			printf("%d%c, ", tab[i], alphabet[i]);
		}
		else if (tab[i] != 0 && count == 1)
			printf("%d%c\n", tab[i], alphabet[i]);
		i++;
	}
}
	
void	count_alpha(char *str)
{
	int	i;
	int	alpha[26];
	char	*decap;
	i = 0;
	while (i < 26)
	{
		alpha[i] = 0;
		i++;
	}
//	printf("%d\n", alpha[10]);
	i = 0;
	decap = ft_decap(str);
//	printf("%d\n", decap[0]);
	while (decap[i])
	{
		if (decap[i] >= 97 && decap[i] <=122)
		{
			alpha[decap[i] - 97]++;
		}
		i++;
	}
//	printf("%d%d%d\n", alpha[0], alpha[1], alpha[2]);
	print_alpha(alpha);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		count_alpha(av[1]);
	//printf("\n");
}

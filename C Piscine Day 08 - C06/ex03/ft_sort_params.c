#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}

void	ft_sort_string(int ac, char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < ac - 1)
	{
		j = 1;
		while (j < ac - i)
		{
			if (ft_strcmp(av[j], av[j + 1]) < 0)
			{
				tmp = av[j];
				av[j] = av[j + 1];
				av[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	ft_sort_string(ac, av);
	i = ac - 1;
	while (i > 0)
	{
		ft_putstr(av[i]);
		write(1, "\n", 1);
		i--;
	}
}

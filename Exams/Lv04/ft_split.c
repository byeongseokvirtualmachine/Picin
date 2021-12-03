#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


char	*ft_strdup(char *str)
{
	int	i;
	int	len;
	char	*dst;

	i = 0;
	len = ft_strlen(str);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	while (str[i] > 32 && str[i] < 127)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	count_ac(char *str)
{
	int	ac;
	int	i;

	ac = 1;
	i = 0;
	while (str[i] <= 32 && str[i] != '\0')
		i++;
	while (str[i])
	{
		if (str[i - 1] <= 32 && str[i] > 32 && str[i] < 127)
			ac++;
		i++;
	}
	return (i);
}

char	**ft_split(char *str)
{
	int	i;
	int	j;
	char	**tab;

	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (count_ac(str) + 1));
	while (str[i] <= 32 && str[i] != '\0')
		i++;
	while (str[i])
	{
		if (str[i] > 32 && str[i] < 127)
		{
			tab[j] = ft_strdup(&str[i]);
			while (str[i] > 32 && str[i] < 127)
				i++;
			j++;
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}

void	ft_print_hex(unsigned char c)
{
	char *radix;

	radix = "0123456789abcdef";
	write(1, &radix[c / 16], 1);
	write(1, &radix[c % 16], 1);
}

void	ft_print_char(unsigned char c)
{
	if (c >= ' ' && c <= '~')
		write(1, &c, 1);
	else
		write(1, ".", 1);
}

void	print_memory(const void *addr, size_t size)
{
	size_t i;
	size_t j;
	unsigned char *ptr;

	i = 0;
	j = 0;
	ptr = (unsigned char*)addr;
	while (i < size)
	{
		j = 0;
		while (j < 16 && i + j < size)
		{
			ft_print_hex(ptr[i + j]);
			if (j % 2)
				write(1, " ", 1);
			j++;
		}
		while (j < 16)
		{
			write(1, "  ", 2);
			if (j % 2)
				write(1, " ", 1);
			j++;
		}
		j = 0;
		while (j < 16 && i + j < size)
		{
			ft_print_char(ptr[i + j]);
			j++;
		}
		write(1, "\n", 1);
		i += 16;
	}
}

int	main (int ac, char **av)
{
	char	**tab;

	tab = ft_split(av[ac - 1]);
	printf("main: $%s$\n", av[ac - 1]);
	printf("sizeof tab: $%ld$\n", sizeof(tab));
	printf("sizeof tab[]: $%ld$\n", sizeof(tab[0]));
	print_memory(tab, sizeof(tab));
	printf("tab[0] $%s$\n", tab[0]);
	print_memory(tab[0], sizeof(tab[0]));
	printf("tab[1] $%s$\n", tab[1]);
	print_memory(tab[1], sizeof(tab[1]));
	printf("tab[2] $%s$\n", tab[2]);
	print_memory(tab[2], sizeof(tab[2]));
	printf("tab[3] $%s$\n", tab[3]);
	print_memory(tab[3], sizeof(tab[3]));
	printf("tab[4] $%s$\n", tab[4]);
	print_memory(tab[4], sizeof(tab[4]));
	printf("tab[5] $%s$\n", tab[5]);
}

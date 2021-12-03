#include <unistd.h>

int	g_tab[16] = {0, };

void	ft_putnbr(unsigned char c)
{
	if (c >= 0 && c <= 9)
	{
		c = c + '0';
		write(1, &c, 1);
	}
	else if (c >= 10 && c <= 15)
	{
		c = c + 87;
		write(1, &c, 1);
	}
}

void	ft_itoa_putchar(unsigned char c, int status)
{
	if (status == -1)
	{
		if (c >= 32 && c < 127)
			write (1, &c, 1);
		else
			write (1, ".", 1);
	}
	else if (status == 0)
	{
		ft_putnbr(c / 16);
		ft_putnbr(c % 16);
	}
	else
	{
		while (status < 16)
		{
			if (status % 2 == 1)
				write (1, " ", 1);
			write (1, "  ", 2);
			status++;
		}
	}
}

void	ft_print_random(void *addr)
{
	long	address;
	int		i;

	address = (long)addr;
	i = 16;
	while (i > 0)
	{
		i--;
		g_tab[i] = address % 16;
		address = address / 16;
	}
	while (i < 16)
	{
		if (g_tab[i] < 10)
			g_tab[i] = g_tab[i] + '0';
		else if (g_tab[i] >= 10)
			g_tab[i] = g_tab[i] + 'a' - 10;
		write(1, &g_tab[i], 1);
		i++;
	}
	write (1, ": ", 2);
}

void	ft_print_content(unsigned char *temp, int linecount, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < 16 && (i + linecount < size))
	{
		ft_itoa_putchar(temp[i + linecount], 0);
		i++;
		if (i % 2 == 0)
			write (1, " ", 1);
		if (i + linecount == size)
			ft_itoa_putchar(temp[i + linecount], i);
		if (i % 16 == 0 || i + linecount == size)
		{
			while (j < i)
			{
				ft_itoa_putchar(temp[j + linecount], -1);
				j++;
			}
		}
	}
	write (1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*temp;
	unsigned int	i;
	int				linecount;

	temp = (unsigned char *)addr;
	i = 0;
	linecount = 0;
	while (i < size)
	{
		if (i % 16 == 0)
		{
			ft_print_random(temp);
			ft_print_content((unsigned char *)addr, linecount, size);
			linecount = linecount + 16;
			temp += 16;
		}
		i++;
	}
	return (addr);
}

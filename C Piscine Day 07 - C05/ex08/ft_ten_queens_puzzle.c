#include <unistd.h>

int	g_board[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int	g_count = 0;

int	ft_add(int *board)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < i)
		{
			if ((i + board[i] == j + board[j])
				|| (board[i] - i == board[j] - j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_swap(int	*i, int	*j)
{
	int	temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

void	ft_puttab(int *tab)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = tab[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_perm(int i)
{
	int	j;

	if (i == 9)
	{
		if (ft_add(g_board))
		{
			ft_puttab(g_board);
			g_count++;
		}
	}
	else
	{
		j = i;
		while (j < 10)
		{
			ft_swap(&g_board[i], &g_board[j]);
			ft_perm(i + 1);
			ft_swap(&g_board[i], &g_board[j]);
			j++;
		}
	}
	return (g_count);
}

int	ft_ten_queens_puzzle(void)
{
	return (ft_perm(0));
}

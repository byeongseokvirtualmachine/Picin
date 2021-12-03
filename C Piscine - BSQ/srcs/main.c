#include "ft.h"

void	*ft_calloc(unsigned int e_c, unsigned int e_s)
{
	unsigned char	*p;
	int				i;

	p = malloc(e_c * e_s);
	i = e_c * e_s - 1;
	while (i >= 0)
	{
		*(p + i) = 0;
		i--;
	}
	return (p);
}

void	free_memory(struct s_info *info, int **n_tab, char *buf)
{
	int	i;

	free(buf);
	i = 0;
	while (i < info->y)
	{
		free(n_tab[i]);
		i++;
	}
	free(n_tab);
	i = 0;
	while (i < info->y)
	{
		free(info->tab[i]);
		i++;
	}
	free(info->tab);
	free(info);
}

void	normal_states(char *v)
{
	struct s_info	*info;
	int				**n_tab;
	char			*buf;

	info = (struct s_info *)ft_calloc(1, sizeof(struct s_info));
	buf = (char *)ft_calloc(BUFFSIZE, sizeof(char));
	if (ft_read(v, buf))
		return ;
	ft_check(info, buf);
	if (ft_error(info, buf))
	{
		write(2, "map error\n", 10);
		return ;
	}
	n_tab = ft_computing(info);
	ft_max(info, n_tab);
	ft_print_tab(info);
	free_memory(info, n_tab, buf);
}

void	stdin_states(void)
{
	struct s_info	*info;
	int				**n_tab;
	char			*buf;

	info = (struct s_info *)ft_calloc(1, sizeof(struct s_info));
	buf = (char *)ft_calloc(BUFFSIZE, sizeof(char));
	buf[0] = '\0';
	ft_stdin_read(buf);
	ft_check(info, buf);
	if (ft_error(info, buf))
	{
		write(2, "map error\n", 10);
		return ;
	}
	n_tab = ft_computing(info);
	ft_max(info, n_tab);
	ft_print_tab(info);
	free_memory(info, n_tab, buf);
}

int	main(int c, char **v)
{
	int	i;

	i = 1;
	if (c > 1)
	{
		while (i < c)
		{
			normal_states(v[i]);
			if (i < (c - 1))
			{
				write(1, "\n", 1);
			}
			i++;
		}
	}
	else if (c == 1)
	{
		stdin_states();
	}
	return (0);
}

#ifndef FT_H
# define FT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>

# define BUFFSIZE 10000000

typedef struct s_info
{
	int		y;
	int		x;
	char	empty;
	char	obs;
	char	full;
	int		**tab;
	int		maxy;
	int		maxx;
	int		max;
}				t_info;

void	*ft_calloc(unsigned int e_c, unsigned int e_s);
int		ft_error(struct s_info *info, char *str);
int		ft_read(char *v, char *buf);
void	ft_stdin_read(char *buf);
void	ft_check(struct s_info *info, char *str);
int		ft_strlen(char *str);
void	ft_max(struct s_info *info, int **tab);
int		**ft_computing(struct s_info *info);
void	ft_print_tab(struct s_info *info);

#endif

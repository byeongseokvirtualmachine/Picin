#include <unistd.h>
#include "ft.h"

int	ft_info_check(struct s_info *info, char *str, int i)
{
	int	l;

	l = i;
	i = 0;
	while (i < l - 3 && str[i] >= '0' && str[i] <= '9')
		i++;
	if (i != l - 3)
		return (1);
	i = 0;
	while (str[l] != '\0')
	{
		if (!(str[l] == info->empty || str[l] == info->obs || str[l] == '\n'))
			return (1);
		if (str[l] == '\n')
			i++;
		l++;
	}
	if (i != info->y + 1)
		return (1);
	if (info->empty == info->obs || info->obs == info->full
		|| info->full == info->empty)
		return (1);
	if (info->x <= 0 || info->y <= 0)
		return (1);
	return (0);
}

int	ft_error(struct s_info *info, char *str)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	while (str[l] != '\0')
		l++;
	if (i < 4 || ft_info_check(info, str, i) == 1
		|| ((l - i - 1) % info->y != 0))
		return (1);
	l = 0;
	while (l <= info->y)
	{
		if (str[l * (info->x + 1) + i] != '\n')
			return (1);
		l++;
	}
	return (0);
}

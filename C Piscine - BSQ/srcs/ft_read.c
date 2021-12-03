#include "ft.h"

int	ft_read(char *v, char *buf)
{
	int		rfd;

	rfd = open(v, O_RDONLY);
	if (rfd == -1)
	{
		write(2, "map error\n", 10);
		return (1);
	}
	read(rfd, buf, BUFFSIZE);
	close(rfd);
	return (0);
}

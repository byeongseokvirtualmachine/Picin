#include <unistd.h>

int	main(int ac, char** av)
{
	int	i;
	int temp;
	
	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
		{
			if(av[1][i] <= 32 && av[1][i+1] > 32)
				temp = i;
			i++;
		}
		while (av[1][temp+1] > 32)
		{
			write (1, &av[1][temp+1], 1);
			temp++;
		}
	}
	write (1, "\n", 1);
}

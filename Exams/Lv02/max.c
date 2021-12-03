int	max(int* tab, unsigned int len)
{
	unsigned int i;
	int temp;

	i = 0;
	if (len == 0)
		return(0);
	else
	{
		while (i < len - 1)
		{
			if(tab[i] < tab[i+1])
				temp = tab[i+1];
			i++;
		}
	}
	return (temp);
}

#include <stdio.h>
int	main(void)
{
	int	str[4];
	str[0] = 12;
	str[1] = 56;
	str[2] = 34;
	str[3] = 12;
	printf("%d\n", max(str, 4));
}

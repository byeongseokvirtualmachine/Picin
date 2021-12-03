int	is_the_power_of_2(unsigned int n)
{
	while (n > 2)
	{
		if (n % 2 == 0)
			n = n / 2;
		else
			return(0);
	}
	if (n == 2 || n == 1)
		return (1);
	else
		return (0);
}

#include <stdio.h>
int main (void)
{
	printf("%d\n", is_the_power_of_2(-16));
	printf("%d\n", is_the_power_of_2(1));
	printf("%d\n", is_the_power_of_2(4294967297));
	printf("%d\n", 0xffffffff+1);
}

unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	int	result;

	result = 0;
	i = 8;
	while (i > 0)
	{
		result = result * 2 + octet % 2;
		octet = octet / 2;
		i--;
	}
	return (result);
}

#include <stdio.h>
int	main(void)
{
	printf("%d\n", reverse_bits(38));
}

unsigned char	swap_bits(unsigned char octet)
{
	int	a;
	int	b;

	a = octet / 16;
	b = octet % 16;
	octet = b * 16 + a;
	return(octet);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", swap_bits(65));
}

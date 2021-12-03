int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	minus;
	int	result;

	i = 0;
	minus = 1;
	result = 0;

	if(str[i] == '-')
	{
		minus = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		result = result * str_base;
		if (str[i] >= '0' && str[i] <= '9')
			result = result + str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			result = result + str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'z')
			result = result + str[i] - 'a' + 10;
		i++;
	}
	return (result * minus);
}

#include <stdio.h>
int	main (void)
{
	printf("%d\n", ft_atoi_base("-123", 3));
}

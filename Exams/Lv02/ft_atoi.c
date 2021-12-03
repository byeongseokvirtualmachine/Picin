int	ft_atoi(const char* str)
{
	int	i;
	int minus;
	int result;

	i = 0;
	minus = 1;
	result = 0;
	while ((str[i] >= 0 && str[i] <= 32) || str[i] == 127)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result *= 10;
		result = result + str[i] - '0';
		i++;
	}
	return (result * minus);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi("   -+----123342424"));
	return (0);
}

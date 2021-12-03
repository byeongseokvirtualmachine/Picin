char	*ft_strrev(char *str)
{
	char temp;
	int i;
	int size;

	i = 0;
	size = 0;
	while (str[i])
		i++;
	size = i;
	i = 0;
	while (i < (size / 2))
	{
		temp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = temp;
		i++;
	}
	return (str);
}

#include <stdio.h>
int	main(void)
{
	char str[6] = {'h', 'e', 'l', 'l', 'o'};
	ft_strrev(str);
	printf("%s\n", str);
}

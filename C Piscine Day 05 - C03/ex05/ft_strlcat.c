unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	a;
	unsigned int	b;

	a = 0;
	b = 0;
	while (dest[a] != '\0' && a < size)
	{
		a++;
	}
	while (src[b] != '\0' && (a + b + 1) < size)
	{
		dest[a + b] = src[b];
		b++;
	}
	if (a < size)
	{
		dest[a + b] = '\0';
	}
	return (a + ft_strlen(src));
}

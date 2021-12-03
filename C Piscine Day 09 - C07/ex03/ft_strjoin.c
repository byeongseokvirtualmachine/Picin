#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	check_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (i < size)
	{
		l += ft_strlen(strs[i]);
		i++;
		if (i < size)
			l += ft_strlen(sep);
	}
	return (l);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*pdst;

	pdst = dest;
	while (*pdst != '\0')
		pdst++;
	while (*src != '\0')
	{
		*pdst = *(unsigned char *)src;
		pdst++;
		src++;
	}
	*pdst = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		l;
	char	*str;

	l = check_total_len(size, strs, sep);
	str = (char *)malloc(sizeof(char) * (l + 1));
	str[0] = '\0';
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		i++;
		if (i < size)
			ft_strcat(str, sep);
	}
	return (str);
}

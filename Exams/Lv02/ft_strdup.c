#include <stdlib.h>

char	* ft_strdup(char *src)
{
	int	i;
	char	*temp;
	int	len;

	while (src[i])
		i++;
	len = i;
	temp = (char*)malloc(sizeof(char) * (len+1));
	if (copy == NULL)
		return (NULL);
	while (src[i])
	{
		temp[i] = src[i];
		i++;
	}
	copy[i] = '\0'
	return (copy);
}
	

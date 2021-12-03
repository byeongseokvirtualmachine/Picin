char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*tmp;

	tmp = dest;
	while (*tmp != '\0')
		tmp++;
	while (*src != '\0' && nb > 0)
	{
		*tmp = *(unsigned char *)src;
		tmp++;
		src++;
		nb--;
	}
	*tmp = '\0';
	return (dest);
}

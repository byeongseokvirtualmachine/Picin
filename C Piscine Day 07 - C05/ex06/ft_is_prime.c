int	ft_is_prime(int nb)
{
	long long	i;
	long long	result;

	i = 2;
	result = 0;
	if (nb <= 1)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

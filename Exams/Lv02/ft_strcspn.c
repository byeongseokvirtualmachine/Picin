#include <stdlib.h>

size_t	ft_strcspn(const char* s, const char* reject)
{
	size_t a;
	size_t b;

	a = 0;
	b = 0;
	while (s[a])
	{
		b = 0;
		while (reject[b])
		{
			if (s[a] == reject[b])
				return (a+1);
			b++;
		}
		a++;
	}
	return (a+1);
}

#include <stdio.h>

int main (void)
{
	printf("%zu\n", ft_strcspn("abcdef", "cfg"));
	return (0);
}

#include <stdlib.h>

int	ft_match(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_count_ac(char *str, char *charset)
{
	int	i;
	int	ac;

	i = 0;
	ac = 0;
	while (str[i])
	{
		if (i == 0 && ft_match(str[i], charset) == 0)
			ac++;
		else if (i > 0 && ft_match(str[i - 1], charset) == 1
			&& (ft_match(str[i], charset) == 0))
			ac++;
		i++;
	}
	return (ac);
}

int	ft_new_tab(char **tab, int i, char *str, char *charset)
{
	int	j;

	j = i;
	while (str[j] && ft_match(str[j], charset) == 0)
		j++;
	tab[0] = (char *)malloc(sizeof(char) * (j - i + 1));
	j = 0;
	while (str[i] && ft_match(str[i], charset) == 0)
	{
		tab[0][j] = str[i];
		i++;
		j++;
	}
	tab[0][j] = '\0';
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		ac;
	char	**tab;

	i = 0;
	ac = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_count_ac(str, charset) + 1));
	while (str[i] != '\0')
	{
		if (i > 0 && ft_match(str[i - 1], charset) == 1
			&& ft_match(str[i], charset) == 0)
		{
			i = ft_new_tab((tab + ac), i, str, charset);
			ac++;
		}
		else if (i == 0 && ft_match(str[i], charset) == 0)
		{
			i = ft_new_tab((tab + ac), i, str, charset);
			ac++;
		}
		else
			i++;
	}
	tab[ac] = 0;
	return (tab);
}

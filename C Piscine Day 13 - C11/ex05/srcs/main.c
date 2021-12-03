#include "ft.h"

char	ft_valid_op(char *tab)
{
	if (tab[0] == '\0' || tab[1] != '\0')
		return (0);
	if (!(tab[0] == '+' || tab[0] == '-' || tab[0] == '*'
			|| tab[0] == '/' || tab[0] == '%'))
		return (0);
	return (tab[0]);
}

int	ft_error(int a, char op, int b, int	c)
{
	a++;
	if (op == '/' && b == 0)
	{
		if (c == 1)
			ft_putstr("Stop : division by zero\n");
		return (1);
	}
	else if (op == '%' && b == 0)
	{
		if (c == 1)
			ft_putstr("Stop : modulo by zero\n");
		return (1);
	}
	return (0);
}

void	ft_do_op(int a, char op, int b)
{
	int		r;
	int		i;
	char	*arr_op;
	int		(*do_op[5])(int, int);

	i = 0;
	r = 0;
	arr_op = "+-/*%";
	do_op[0] = &ft_add;
	do_op[1] = &ft_minus;
	do_op[2] = &ft_divide;
	do_op[3] = &ft_multiply;
	do_op[4] = &ft_modulo;
	while (i < 5)
	{
		if (op == arr_op[i] && ft_error(a, op, b, 0) != 1)
			r = (do_op[i])(a, b);
		i++;
	}
	if (ft_error(a, op, b, 1) != 1)
	{
		ft_putnbr(r);
		ft_putstr("\n");
	}
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	char	op;

	if (argc == 4)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		op = ft_valid_op(argv[2]);
		if (op != 0)
			ft_do_op(a, op, b);
		else
		{
			ft_putnbr(0);
			ft_putstr("\n");
		}
	}
	return (0);
}

#include "ft_printf.h"

static int	ft_is_space(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '\t')
			return (0);
		if (str[i] == '\v' || str[i] == '\n' || str[i] == '\f')
			return (0);
		i ++;
	}
	return (1);
}


static int	verif_errors(char	*str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(str) < 2)
		return (0);
	while (str[i])
	{
		if (ft_is_space(&str[i]) == 0)
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i ++;
	}
	return (1);
}

int	ft_putnbr_base(unsigned int	nbr, char	*base)
{
	long unsigned int	intlong;
	long unsigned int	length;
	int			counter;

	counter = 0;
	intlong = nbr;
	length = ft_strlen(base);
	if (verif_errors(base) == 1)
	{
		if (intlong >= length)
			counter = ft_putnbr_base((intlong / length), base);
		counter += ft_putchar_counting(base[intlong % length]);
	}
	return (counter);
}

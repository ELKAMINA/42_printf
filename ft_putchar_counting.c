
#include "ft_printf.h"

int	ft_putchar_counting(char c)
{
	write (1, &c, 1);
	return (1);
}

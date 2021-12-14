#include "libftprintf.h"


static int	display_count(char	c, va_list	list)
{
	int	prct_counter;

	prct_counter = 0;
	if (c == 'c')
		prct_counter += ft_putchar_counting(va_arg(list, int));
	if (c == 's')
		prct_counter += ft_putstr_counting(va_arg(list, char	*));
	if (c == 'd'|| c == 'i' )
		prct_counter += ft_putnbr_counting(va_arg(list, int));
	if (c == 'X')
		prct_counter += ft_putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF");
	if (c == 'x')
		prct_counter += ft_putnbr_base(va_arg(list, unsigned int), "0123456789abcdef");
	if (c == '%')
		prct_counter += ft_putchar_counting(va_arg(list, int));
	//printf("prct_counter %d", prct_counter);
	return (prct_counter);

}

int ft_printf(const char *fmt, ...)
{
	int		i;
	int		counter;
	va_list	j;

	i = 0;
	counter = 0;
	va_start(j, fmt);
	while (fmt[i] != '\0')
	{
		while (fmt[i] != '\0' && fmt[i] != '%')
		{
			ft_putchar_counting(fmt[i]);
			i ++;
		}
		if (fmt[i] == '%')
			counter = display_count(fmt[++i], j);
		else
			break ;
		//printf("counter %d\n", counter);
		i++;
	}
	//printf("counter + i %d\n", counter+i);
	return (counter + i);
}

int	main()
{
	char	*str;
	int	entier;

	str = "HELLO";
	entier = 454;
	ft_printf("Hey%skdd %d", str, entier);
}


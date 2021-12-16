#include "ft_printf.h"


static int	display_count(char	c, va_list	list)
{
	int	prct_counter;

	prct_counter = 0;
	if (c == 'c')
		prct_counter = ft_putchar_counting(va_arg(list, int));
	if (c == 's')
		prct_counter = ft_putstr_counting(va_arg(list, char	*));
	if (c == 'd'|| c == 'i' )
		prct_counter = ft_putnbr_counting(va_arg(list, int));
	if (c == 'X')
		prct_counter = ft_putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF");
	if (c == 'x')
		prct_counter = ft_putnbr_base(va_arg(list, unsigned int), "0123456789abcdef");
	if (c == '%')
		prct_counter = ft_putchar_counting('%');
	if (c == 'u')
		prct_counter = ft_putnbr_base(va_arg(list, unsigned int), "0123456789");
	if (c == 'p')
	{
		prct_counter = ft_putstr_counting("0x");
		prct_counter += ft_putnbr_base(va_arg(list, unsigned long long), "0123456789abcdef");
	}
	return (prct_counter);
}

int ft_printf(const char *fmt, ...)
{
	int		i;
	int		counter;
	int		k;
	va_list	j;

	i = 0;
	k = 0;
	counter = 0;
	va_start(j, fmt);
	while (fmt[i] != '\0')
	{
		while (fmt[i] != '\0' && fmt[i] != '%')
		{
			ft_putchar_counting(fmt[i]);
			i ++;
			k ++;
		}
		if (fmt[i] == '%')
		{
			i ++;
			counter += display_count(fmt[i], j);
		}
		else
			break ;
		i ++;
	}
	va_end(j);
	return (counter + k);
}

/*int	main()
{
	//char	*str = "3b";
	//int min = 0;
	//int max = 0;
	//

	//unsigned int	ptr = 5000000;
	//str = "salut";
	printf("\nnumero = %d\n",printf("%p %p", 0, 0));
	//printf("%d", ft_printf("je %d", -1));
	//printf("%d", ft_printf("%%"));
	//printf("%d", ft_printf("NULL %s NULL", str));
}
*/

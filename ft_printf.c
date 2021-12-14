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
		//printf("----je suis le I apres boucle 1 --%d", i);
		if (fmt[i] == '%')
		{
			
			//printf("je suis le I avant%d", i);
			counter = display_count(fmt[++i], j);
			//printf("je suis le counter apres %d", counter);
		}
		else
			break ;
		i ++;
		//printf("---je suis le i fin de boucle--- %d", i);
	}
//	printf("je suis le i %d\n", k);
	return (counter + k);
}

int	main()
{
	char	*str;
	//int	entier;

	str = "HELLO";
	//entier = 454;
	//printf("%d", ft_printf("Test%spoj", str));
	//printf("%d", printf("Test%spoj", str));
}


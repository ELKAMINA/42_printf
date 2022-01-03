/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:22:06 by ael-khat          #+#    #+#             */
/*   Updated: 2022/01/03 19:30:18 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	display_count(char c, va_list list)
{
	int	c;

	c = 0;
	if (c == 'c')
		c = ft_putchar_counting(va_arg(list, int));
	if (c == 's')
		c = ft_putstr_counting(va_arg(list, char *));
	if (c == 'd' || c == 'i')
		c = ft_putnbr_counting(va_arg(list, int));
	if (c == 'X')
		c = ft_putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF");
	if (c == 'x')
		c = ft_putnbr_base(va_arg(list, unsigned int), "0123456789abcdef");
	if (c == '%')
		c = ft_putchar_counting('%');
	if (c == 'u')
		c = ft_putnbr_base(va_arg(list, unsigned int), "0123456789");
	if (c == 'p')
	{
		c = ft_putstr_counting("0x");
		c += ft_putnbr_base(va_arg(list, unsigned long long),
				"0123456789abcdef");
	}
	return (c);
}

int	ft_printf(const char *fmt, ...)
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
		if (fmt[i++] == '%')
			counter += display_count(fmt[i], j);
		else
			break ;
		i ++;
	}
	va_end(j);
	return (counter + k);
}

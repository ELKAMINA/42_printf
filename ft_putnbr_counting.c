/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_counting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:58:30 by ael-khat          #+#    #+#             */
/*   Updated: 2021/12/14 15:53:18 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_counting(int n)
{
	int counter;

	counter = 0;
	if (n == -2147483648)
		counter = ft_putstr_counting("-2147483648");
	else if (n < 0)
	{
		counter = ft_putchar_counting('-');
		counter += ft_putnbr_counting(-n);
	}
	else if (n >= 10)
	{
		counter += ft_putnbr_counting(n / 10);
		counter += ft_putchar_counting(n % 10 + '0');
	}
	else
	{
		counter = ft_putchar_counting(n + '0');
	}
	return (counter);
}

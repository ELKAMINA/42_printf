/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_counting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:59:48 by ael-khat          #+#    #+#             */
/*   Updated: 2021/12/14 14:30:36 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_counting(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		i = ft_putstr_counting("(null)");
	}
	else
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i ++;
		}
	}
	return (i);
}

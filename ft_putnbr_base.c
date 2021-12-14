/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:42:41 by ael-khat          #+#    #+#             */
/*   Updated: 2021/07/18 10:09:52 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

int	ft_is_space(char	*str)
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

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i ++;
	}
	return (i);
}

int	verif_errors(char	*str)
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

void	ft_putnbr_base(int	nbr, char	*base)
{
	long int	intlong;
	long int	length;
	int			i;

	i = 0;
	intlong = nbr;
	length = ft_strlen(base);
	if (verif_errors(base) == 1)
	{
		if (intlong < 0)
		{
			ft_putchar('-');
			intlong *= -1;
		}
		if (intlong >= length)
			ft_putnbr_base((intlong / length), base);
		ft_putchar(base[intlong % length]);
	}
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:13:24 by ael-khat          #+#    #+#             */
/*   Updated: 2021/12/14 14:26:22 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************* */

#ifndef LIBFTPRINTF_H
# define LIBFTRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>


int			ft_putnbr_counting(int n);
int			ft_putchar_counting(char s);
int			ft_putnbr_base(int n, char *s);
int			ft_putstr_counting(char *s);

#endif


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>


int			ft_putnbr_counting(int n);
int			ft_putchar_counting(char s);
int			ft_putnbr_base(int n, char *s);
int			ft_putstr_counting(char *s);
int			ft_printf(const char	*fmt, ...);
#endif

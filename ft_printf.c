
int	display_count(char	c, va_list	list)
{
	int	prct_counter;

	prct_counter = 0;
	if (c == 'c')
		prct_counter = ft_putchar_counting(va_arg(list, int));
	else if (c == 's')
		prct_counter = ft_putstr_counting(va_arg(list, char	*));
	else if (c == 'd' )
		

int ft_printf(const char *fmt, ...)
{
	int		i;
	va_list par;
	int		counter;
	int		j;
	char	*s;

	i = 0;
	va_start (par, fmt);
	while (fmt && fmt[i])
	{
		if (fmt[i] == "%")
		{
			i ++;
			counter = display_count(fmt[i], par);
		}

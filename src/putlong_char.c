#include "ft_printf.h"

int	putlong_char(long sh)
{
	char	tmp;

	tmp = (char)sh;
	ft_putchar(tmp);
	return (1);
}

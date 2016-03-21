#include "ft_printf.h"

int	putlong_char(long ch)
{
	char	sh;

	sh = (char)ch;
	ft_putchar(sh);
	return (1);
}

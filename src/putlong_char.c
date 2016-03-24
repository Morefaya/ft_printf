#include "ft_printf.h"
#include <wchar.h>

int	putlong_char(t_opt opt)
{
	if (opt.type == 'c')
	{
		ft_putchar(opt.conv);
		return (1);
	}
	else if (opt.type == 'C')
	{
		ft_putnbr(opt.conv);
	}
	return (0);
}

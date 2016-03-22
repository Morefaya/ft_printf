

#include "ft_printf.h"

void	putun_nbr(unsigned long nbr, t_opt opt)
{
	unsigned long	base;

	if (opt.type == 'x' || opt.type == 'X')
		base = 16;
	else if (opt.type == 'o')
		base = 8;
	else
		base = 10;
	if (nbr == 9223372036854775807)
	{
		ft_putstr("9223372036854775807");
		return ;
	}
	if (nbr > base - 1)
	{
		putun_nbr(nbr / base, opt);
		putun_nbr(nbr % base, opt);
	}
	else
		ft_putchar('0' + nbr);
}

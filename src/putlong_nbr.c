

#include "ft_printf.h"

static long	check_base(t_opt opt)
{
	if (opt.type == 'x' || opt.type == 'X')
		return (16);
	else if (opt.type == 'o')
		return (8);
	else
		return (10);
}

void	putlong_nbr(long nbr, t_opt opt)
{
	long	base;
	char	*base_set;

	base = check_base(opt);
	if (opt.type == 'x' || opt.type == 'X')
		base_set = (opt.type == 'x') ?
			"0123456789abcdef" : "0123456789ABCDEF";
	else if (opt.type == 'o')
		base_set = "01234567";
	else
		base_set = "0123456789";
	if (nbr > base - 1)
	{
		putlong_nbr(nbr / base, opt);
		putlong_nbr(nbr % base, opt);
	}
	else
		ft_putchar(base_set[nbr]);
}

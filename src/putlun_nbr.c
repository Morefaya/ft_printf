

#include "ft_printf.h"

static unsigned long	check_base(t_opt opt)
{
	if (ft_check_charset(opt.type, "xXp"))
		return (16);
	else if (opt.type == 'o' || opt.type == 'O')
		return (8);
	else
		return (10);
}

void	putlun_nbr(unsigned long nbr, t_opt opt)
{
	unsigned long	base;
	char		*base_set;

	base = check_base(opt);
	if (ft_check_charset(opt.type, "xXp"))
		base_set = (ft_check_charset(opt.type, "xp")) ?
			"0123456789abcdef" : "0123456789ABCDEF";
	else if (opt.type == 'o' || opt.type == 'O')
		base_set = "01234567";
	else
		base_set = "0123456789";
	if (nbr > base - 1)
	{
		putlun_nbr(nbr / base, opt);
		putlun_nbr(nbr % base, opt);
	}
	else
		ft_putchar(base_set[nbr]);
}

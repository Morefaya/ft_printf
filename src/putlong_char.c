#include "ft_printf.h"
#include <wchar.h>

static int	check_mask(t_opt opt)
{
	int	size;
 
	if ((int)opt.conv < 0 || opt.conv > 0x10FFFF)
		return (-1);
	size = size_base(opt);
	if (size <= 7)
		return (MASK_0);
	else if (size <= 11)
		return (MASK_1);
	else if (size <= 16)
		return (MASK_2);
	else
		return (MASK_3);
}

int	putlong_char(t_opt opt)
{
	int	i;
	int	size;
	int	mask;
	long	ret;

	ret = 0;
	if (opt.type == 'c')
	{
		ft_putchar(opt.conv);
		return (1);
	}
	else if (opt.type == 'C')
	{
		i = 0;
		size = size_base(opt);
		mask = check_mask(opt);
		/*putint_base(mask, "01");
		ft_putchar('\n');
		putint_base(size, "0123456789");
		ft_putchar('\n');
		ft_putnbr(ft_size_base(mask, 2));*/
		while (i < ft_size_base(mask, 2))
		{
			if (!(mask & ft_pow(2, i)))
			{
				ret = (opt.conv & ft_pow(2, i)) | 
				opt.conv <<= 1;
				putint_base(opt.conv, "01");
				ft_putchar('@');
			}
			else
			{
				putint_base(ft_pow(2, 5), "01");
				ft_putchar('#');
			}
			i++;
		}
		/*putint_base(MASK_3, "01");
		ft_putchar('\n');
		putint_base(ft_pow(2, 4), "01");*/
	}
	return (0);
}

#include "ft_printf.h"
#include <wchar.h>

int	putlong_char(t_opt opt)
{
	/*int	i;
	int	size;*/

	if (opt.type == 'c')
	{
		ft_putchar(opt.conv);
		return (1);
	}
	else if (opt.type == 'C')
	{
		/*i = 0;
		size = size_base(opt);
		while (i < size)
		{
			if (!(MASK_0 & ft_pow(2, i)))
			{
				opt.conv <<= 1;
				putint_base(opt.conv, "01");
			}
			else
				putint_base(ft_pow(2, 6), "01");
			i++;
		}*/
		putint_base(U_MASK_2, "01");
		ft_putchar('\n');
		putint_base(ft_pow(2, 4), "01");
		/*//ft_putnbr(atoi_base("1100000010000000", "01"));
		ft_putchar('\n');
		putint_base(U_MASK_2, "01");
		//ft_putnbr(atoi_base("111000001000000010000000", "01"));
		ft_putchar('\n');
		putint_base(U_MASK_3, "01");
		//ft_putnbr(atoi_base("11110000100000001000000010000000", "01"));*/
	}
	return (0);
}

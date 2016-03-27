#include "ft_printf.h"
#include <wchar.h>
#include <unistd.h>

static int	check_mask(t_opt opt)
{
	int	size;
 
	if ((int)opt.conv < 0 || opt.conv > 0x10FFFF)
		return (-1);
	size = size_base(opt);
	if (opt.conv <= 0x7F)
		return (MASK_0);
	else if (opt.conv <= 0x7FF)
		return (MASK_1);
	else if (opt.conv <= 0xFFFF)
		return (MASK_2);
	else
		return (MASK_3);
}

static int	select_u_mask(int mask)
{
	if (mask == MASK_0)
		return (U_MASK_0);
	else if (mask == MASK_1)
		return (U_MASK_1);
	else if (mask == MASK_2)
		return (U_MASK_2);
	else if (mask == MASK_3)
		return (U_MASK_3);
	return (0);
}

static void	print_c(long ret)
{
	if (ret > 0x7F)
		print_c(ret >> 8);
	ret = (char)ret;
	write(1, &ret, 1);
}

int	putlong_char(t_opt opt)
{
	int	i;
	int	mask;
	long	ret;
	//char	a = 206;
	//char	s = 177;

	ret = 0;
	if (opt.type == 'c')
	{
		ft_putchar(opt.conv);
		return (1);
	}
	else if (opt.type == 'C')
	{
		i = 0;
		mask = check_mask(opt);
		while (i < ft_size_base(mask, 2))
		{
			if (mask & ft_pow(2, i))
			{
				ret |= ((1 & opt.conv) << i);
				opt.conv >>= 1;
			}
			i++;
		}
		mask = select_u_mask(mask);
		ret |= mask;
		//write(1, &a, 1);
		//write(1, &s, 1);
		print_c(ret);
		//ft_putchar('\n');
		//putint_base(ret, "01");
		//write(1, &ret, 1);
		//ret >>= 8 ;
		//write(1, &ret, 1);
		return (2);
	}
	return (0);
}

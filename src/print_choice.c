#include "ft_printf.h"

static void choice_int(t_opt opt, int *ret, int signe_i)
{
	if ((!opt.conv && opt.pres_on && !opt.presi))
		return ;
	putnbr(signe_i * opt.conv, ret);
}

static void choice_oO(t_opt opt, int *ret)
{
	if (!opt.conv && opt.pres_on && !opt.attri.diez)
		return ;
	putlun_nbr(opt.conv, opt, ret);
}

static void choice_xX(t_opt opt, int *ret)
{
	if (!opt.conv && opt.pres_on && !opt.presi)
		return ;
	putlun_nbr(opt.conv, opt, ret);
}

static void choice_Uup(t_opt opt, int *ret)
{
	if (!opt.conv && opt.pres_on && !opt.presi)
		return ;
	putlun_nbr(opt.conv, opt, ret);
}

int	print_choice(t_opt opt)
{
	int	ret;
	int	signe_l;
	int	signe_i;

	signe_l = (opt.conv < 0) ? -1 : 1;
	signe_i = ((int)opt.conv < 0) ? -1 : 1;
	ret = 0;
	if (opt.type == 'D' || (ft_check_charset(opt.type, "id")
		&& ft_check_charset(opt.m_len, "lLjz")))
		putlong_nbr(signe_l * opt.conv, &ret);
	else if (ft_check_charset(opt.type, "di") && opt.m_len == 'h')
		putshort_nbr(opt.conv, &ret);
	else if (ft_check_charset(opt.type, "di") && opt.m_len == 'H')
		putchar_nbr(opt.conv, &ret);
	else if (ft_check_charset(opt.type, "Uup"))
		choice_Uup(opt, &ret);
	else if (ft_check_charset(opt.type, "xX"))
		choice_xX(opt, &ret);
	else if (opt.type == 'o' || opt.type == 'O')
		choice_oO(opt, &ret);
	else
		choice_int(opt, &ret, signe_i);
	return (ret);
}

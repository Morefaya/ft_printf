/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:30:19 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/28 22:45:17 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static void	deal_zero(t_opt opt, int *size, int *ret, int cond)
{
	if (opt.attri.moins && opt.attri.zero && opt.conv)
		return ;
	else if (opt.attri.moins && opt.attri.diez && opt.attri.zero)
		return ;
	if (ft_check_charset(opt.type, "dD") && opt.attri.plus
		&& opt.attri.zero && opt.width && (int)opt.conv < 0)
		(*size)++;
	while (*size > 0)
	{
		if (cond)
			ft_putchar('0');
		(*ret)++;
		(*size)--;
	}
}

int			print_zero_left(t_opt opt, int cond)
{
	int	size;
	int	ret;

	ret = 0;
	if (opt.attri.zero && !opt.pres_on && opt.width)
	{
		size = opt.width - size_base(opt);
		if (check_signe_moins(opt) == -1)
			size--;
	}
	else
		size = opt.presi - size_base(opt);
	if ((opt.type == 'p' && opt.attri.zero && opt.width))
		size -= 2;
	else if ((ft_check_charset(opt.type, "diD")
		&& opt.attri.moins && opt.attri.zero)
		|| (ft_check_charset(opt.type, "diD")
		&& opt.attri.plus && opt.attri.zero && opt.conv))
		size--;
	else if (ft_check_charset(opt.type, "xX")
		&& opt.attri.zero && opt.attri.diez)
		size -= 2;
	if (ft_check_charset(opt.type, "dDi") && opt.attri.zero && !opt.attri.diez
		&& opt.width && !opt.pres_on && !opt.presi && !opt.conv)
	{
		if ((opt.attri.plus && !opt.attri.space && !opt.attri.moins)
			|| (!opt.attri.plus && opt.attri.space && !opt.attri.moins)
			|| (!opt.attri.plus && !opt.attri.space && opt.attri.moins))
			size--;
	}
	deal_zero(opt, &size, &ret, cond);
	if (!ret && opt.attri.diez && ft_check_charset(opt.type, "oO"))
	{
		if (cond && opt.conv)
		{
			ft_putchar('0');
			ret++;
		}
	}
	return (ret);
}*/

static int	print_space_right(t_opt opt, int ret_p)
{
	int	size;
	int	ret;

	ret = 0;
	size = opt.width - ret_p;

	while (size > 0)
	{
		ft_putchar(' ');
		ret++;
		size--;
	}
	return (ret);
}
/*
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
	{
		if (!opt.conv && opt.pres_on && !opt.presi)
			return (0);
		putlun_nbr(opt.conv, opt, &ret);
	}
	else if (ft_check_charset(opt.type, "xX"))
	{
		if (!opt.conv && opt.pres_on && !opt.presi)
			return (0);
		putlun_nbr(opt.conv, opt, &ret);
	}
	else if (opt.type == 'o' || opt.type == 'O')
	{
		if (!opt.conv && opt.pres_on && !opt.attri.diez)
			return (0);
		putlun_nbr(opt.conv, opt, &ret);
	}
	else
	{
		if ((!opt.conv && opt.pres_on && !opt.presi))
			return (ret);
		putnbr(signe_i * opt.conv, &ret);
	}
	return (ret);
}*/

int			print_nbr(t_opt opt)
{
	int	ret;

	ret = 0;
	ret += print_space_left(opt);
	ret += print_prefix(opt, 1);
	ret += print_zero_left(opt, 1);
	ret += print_choice(opt);
	if (opt.attri.moins)
		ret += print_space_right(opt, ret);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:30:19 by jcazako           #+#    #+#             */
/*   Updated: 2016/05/17 21:37:44 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	deal_zero(int *size, int *ret, int cond)
{
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
	if (opt.attri.zero && !opt.presi && opt.width > opt.presi)
	{
		size = opt.width - size_base(opt);
		if (check_signe_moins(opt) == -1)
			size--;
	}
	else
		size = opt.presi - size_base(opt);
	deal_zero(&size, &ret, cond);
	if (!ret && opt.attri.diez && ft_check_charset(opt.type, "oO"))
	{
		if (cond)
			ft_putchar('0');
		ret++;
	}
	return (ret);
}

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

static int	print_choice(t_opt opt)
{
	int	ret;
	int	signe_l;
	int	signe_i;

	signe_l = (opt.conv < 0) ? -1 : 1;
	signe_i = ((int)opt.conv < 0) ? -1 : 1;
	ret = 0;
	if (opt.type == 'D' || (ft_check_charset(opt.type, "id")
				&& ft_check_charset(opt.m_len, "lL")))
		putlong_nbr(signe_l * opt.conv, &ret);
	else if (ft_check_charset(opt.type, "di") && opt.m_len == 'h')
		putshort_nbr(opt.conv, &ret);
	else if (ft_check_charset(opt.type, "di") && opt.m_len == 'H')
		putchar_nbr(opt.conv, &ret);
	else if (ft_check_charset(opt.type, "Upu"))
		putlun_nbr(opt.conv, opt, &ret);
	else if (opt.type == 'x' || opt.type == 'X')
		putlong_base(opt.conv, opt, &ret);
	else if (opt.type == 'o' || opt.type == 'O')
		putlun_nbr(opt.conv, opt, &ret);
	else
		putnbr(signe_i * opt.conv, &ret);
	return (ret);
}

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

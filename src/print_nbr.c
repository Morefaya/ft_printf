/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:30:19 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/21 22:35:32 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbrlen(t_opt opt)
{
	int	len;

	len = size_base(opt);
	if (opt.presi > len)
		return (opt.presi);
	else
		return (len);
}

static int	print_zero(t_opt opt)
{
	int	size;
	int	ret;

	ret = 0;
	if (opt.attri.zero && !opt.presi && opt.width > opt.presi)
	{
		size = opt.width - size_base(opt);
		if (ft_check_charset(opt.type, "diD"))
			size = (opt.conv < 0) ? (size - 1) : size;
	}
	else
		size = opt.presi - size_base(opt);
	while (size > 0)
	{
		ft_putchar('0');
		ret++;
		size--;
	}
	return (ret);
}

static int	print_space_right(t_opt opt)
{
	int	size;
	int	ret;

	ret = 0;
	size = opt.width - nbrlen(opt);
	if (ft_check_charset(opt.type, "di"))
	{
		if ((int)opt.conv < 0 || opt.attri.plus)
			size--;
	}
	else if (opt.type == 'D')
	{
		if (opt.conv < 0 || opt.attri.plus)
			size--;
	}
	while (size > 0)
	{
		ft_putchar(' ');
		ret++;
		size--;
	}
	return (ret);
}
static int	print_prefix(t_opt opt, int ret_z)
{
	if (opt.type == 'x' || opt.type == 'X')
	{
		ft_putstr("0x");
		return (2);
	}
	else if (opt.type == 'o' && !ret_z)
	{
		ft_putchar('0');
		return (1);
	}
	return (0);
}
static int	print_choice(t_opt opt)
{
	int	ret;
	int	signe_l;
	int	signe_i;

	signe_l = (opt.conv < 0) ? -1 : 1;
	signe_i = ((int)opt.conv < 0 ) ? -1 : 1; 
	ret = 0;
	if (opt.type == 'D')
		putlong_nbr(signe_l * opt.conv, opt);
	else if (opt.type == 'u')
		putlong_nbr(opt.conv, opt);
	else if (opt.type == 'x' || opt.type == 'X')
		putlong_nbr(opt.conv, opt);
	else if (opt.type == 'o')
		putlong_nbr(opt.conv, opt);
	else
		ft_putnbr(signe_i * opt.conv);
	ret += size_base(opt);
	return (ret);
}

int		print_nbr(t_opt opt)
{
	int	ret;
	int	ret_z;

	ret = 0;
	ret += print_space_left(opt);
	ret_z = print_zero(opt);
	ret += ret_z;
	ret += print_prefix(opt, ret_z);
	ret += print_choice(opt);
	if (opt.attri.moins)
		ret += print_space_right(opt);
	return (ret);
}

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

int	print_zero_left(t_opt opt, int cond)
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
		if (cond)
			ft_putchar('0');
		ret++;
		size--;
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
int	print_prefix(t_opt opt, int cond)
{
	if (ft_check_charset(opt.type, "xX") && opt.attri.diez)
	{
		if (cond)
		{
			if (opt.type == 'x')
				ft_putstr("0x");
			else
				ft_putstr("0X");
		}
		return (2);
	}
	else if (opt.type == 'o' && !print_zero_left(opt, 0)
		&& opt.attri.diez)
	{
		if (cond)
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
	else if (opt.type == 'U')
		putun_nbr(opt.conv, opt);
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

	ret = 0;
	ret += print_space_left(opt);
	ret += print_prefix(opt, 1);
	ret += print_zero_left(opt, 1);
	ret += print_choice(opt);
	if (opt.attri.moins)
		ret += print_space_right(opt, ret);
	return (ret);
}

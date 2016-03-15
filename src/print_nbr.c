/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:30:19 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/15 11:50:41 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbrlen(t_conv conv, t_opt opt)
{
	int	len;

	len = ft_size_base(conv.s_int, 10);
	if (opt.presi > len)
		return (opt.presi);
	else
		return (len);
}

static int	print_space_left(t_conv conv, t_opt opt)
{
	int		size;
	int		ret;

	ret = 0;
	size = opt.width - nbrlen(conv, opt);
	if (conv.s_int < 0 || opt.attri.plus)
		size--;
	if ((!opt.attri.moins && opt.presi)
		|| (!opt.attri.moins && !opt.attri.zero && !opt.presi))
	{	
		while (size > 0)
		{
			ft_putchar(' ');
			ret++;
			size--;
		}
	}
	if (opt.attri.space && !ret && conv.s_int > 0 && !opt.attri.plus)
	{
		ft_putchar(' ');
		ret++;
	}
	if (conv.s_int < 0)
	{
		ft_putchar('-');
		ret++;
	}
	else if (opt.attri.plus)
	{
		ft_putchar('+');
		ret++;
	}
	return (ret);
}

static void	print_pres_zero(t_conv conv, t_opt opt)
{
	int	size;

	if (opt.attri.zero && !opt.presi && opt.width > opt.presi)
	{
		size = opt.width - ft_size_base(conv.s_int, 10);
		size = (conv.s_int < 0) ? (size -1) : size;
	}
	else
		size = opt.presi - ft_size_base(conv.s_int, 10);
	while (size > 0)
	{
		ft_putchar('0');
		size--;
	}
}

static void	print_space_right(t_conv conv, t_opt opt)
{
	int	size;
	size = opt.width - nbrlen(conv, opt);
	if (conv.s_int < 0 || opt.attri.plus)
		size--;
	while (size > 0)
	{
		ft_putchar(' ');
		size--;
	}
}

void	print_nbr(t_conv conv, t_opt opt)
{
	int	signe;

	signe = 1;
	if (conv.s_int < 0)
		signe = -1;
	print_space_left(conv, opt);
	print_pres_zero(conv, opt);
	ft_putnbr(signe * (conv.s_int));
	if (opt.attri.moins)
		print_space_right(conv, opt);
}

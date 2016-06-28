/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 20:03:08 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/28 16:39:54 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_plus(t_opt opt, int *ret)
{
	if (opt.attri.plus && ft_check_charset(opt.type, "diD"))
	{
		(*ret)++;
		return (1);
	}
	return (0);
}

static int	print_moins(t_opt opt, int *ret)
{
	if (check_signe_moins(opt) == -1)
	{
		(*ret)++;
		return (1);
	}
	return (0);
}

static int	print_opt_space(t_opt opt, int *ret)
{
	if (opt.attri.space && !*ret)
	{
		if (ft_check_charset(opt.type, "di"))
		{
			if ((int)opt.conv > 0 && !opt.attri.plus)
			{
				(*ret)++;
				return (1);
			}
		}
		else if (opt.type == 'D')
		{
			if (opt.conv > 0 && !opt.attri.plus)
			{
				(*ret)++;
				return (1);
			}
		}
	}
	return (0);
}

static void	deal_opt(t_opt opt, int *ret)
{
	if (print_opt_space(opt, ret))
		ft_putchar(' ');
	else if (print_moins(opt, ret))
		ft_putchar('-');
	else if (print_plus(opt, ret))
		ft_putchar('+');
}

int			print_space_left(t_opt opt)
{
	int	size;
	int	ret;

	ret = 0;
	size = opt.width - nbrlen(opt);
	if (check_signe_moins(opt) == -1
		|| (ft_check_charset(opt.type, "diDuU") && opt.attri.plus))
		size--;
	size -= print_prefix(opt, 0);
	if ((!opt.attri.moins && opt.presi)
			|| (!opt.attri.moins && !opt.attri.zero && !opt.presi))
	{
		if (opt.pres_on && !opt.conv && !opt.attri.diez
			&& ft_check_charset(opt.type, "odx") && opt.width && !opt.attri.zero)
		{
			ret++;
			ft_putchar(' ');
		}
		if (ft_check_charset(opt.type, "oO") && opt.attri.diez && opt.width)
			size--;
		while (size > 0)
		{
			ft_putchar(' ');
			ret++;
			size--;
		}
	}
	else if (opt.attri.space && ft_check_charset(opt.type, "diD"))
	{
		ft_putchar(' ');
		ret++;
	}
	deal_opt(opt, &ret);
	return (ret);
}

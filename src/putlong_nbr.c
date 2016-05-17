/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlong_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 21:08:53 by jcazako           #+#    #+#             */
/*   Updated: 2016/05/17 21:09:08 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	check_base(t_opt opt)
{
	if (ft_check_charset(opt.type, "xXp"))
		return (16);
	else if (ft_check_charset(opt.type, "oO"))
		return (8);
	else
		return (10);
}

void		putlong_nbr(long nbr, t_opt opt)
{
	long	base;
	char	*base_set;

	base = check_base(opt);
	if (opt.type == 'x' || opt.type == 'X')
		base_set = (opt.type == 'x') ?
			"0123456789abcdef" : "0123456789ABCDEF";
	else if (opt.type == 'o' || opt.type == 'O')
		base_set = "01234567";
	else
		base_set = "0123456789";
	if (nbr > base - 1)
	{
		putlong_nbr(nbr / base, opt);
		putlong_nbr(nbr % base, opt);
	}
	else
		ft_putchar(base_set[nbr]);
}

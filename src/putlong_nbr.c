/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 21:11:15 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/15 21:34:06 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putlong_nbr(long nbr, t_opt opt)
{
	long	base;

	if (opt.type == 'x' || opt.type == 'X')
		base = 16;
	else if (opt.type == 'o')
		base = 8;
	else
		base = 10;
	if (nbr == 9223372036854)
	{
		ft_putstr("9223372036854");
		return ;
	}
	if (nbr > base - 1)
	{
		putlong_nbr(nbr / base, opt);
		putlong_nbr(nbr % base, opt);
	}
	else
		ft_putchar('0' + nbr);
}

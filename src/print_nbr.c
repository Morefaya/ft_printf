/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:30:19 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/11 14:44:19 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nbr(t_conv conv, t_opt opt)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	if (opt.width)
	{
		size = ft_size_base(conv.u_int, 10);
		i = opt.width - size;
		if (conv.s_int < 0)
			i--;
	}
	if (!opt.attri.moins)
		while (i--)
		{
			if (!opt.attri.zero)
				ft_putchar(' ');
			else
				ft_putchar('0');
		}
	ft_putnbr(conv.s_int);
	if (opt.attri.moins)
		while (i--)
			ft_putchar(' ');
}

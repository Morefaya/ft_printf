/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:30:19 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/11 18:10:37 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_zero(t_conv conv, t_opt opt, int i)
{
	int	signe;

	signe = 1;
	if (i < 0)
	{
		ft_putchar('-');
		signe = -1;
	}
	if (!opt.attri.moins)
		while (i--)
			ft_putchar('0');
	ft_putnbr(signe * conv.s_int);
	if (opt.attri.moins)
		while (i--)
			ft_putchar(' ');
}

static void	print_space(t_conv conv, t_opt opt, int i)
{
	if (!opt.attri.moins)
		while (i--)
			ft_putchar(' ');
	ft_putnbr(conv.s_int);
	if (opt.attri.moins)
		while (i--)
			ft_putchar(' ');
}

void	print_nbr(t_conv conv, t_opt opt)
{
	int	i;
	int	signe;

	i = 0;
	signe = 1;
	if (opt.width)
	{
		i = opt.width - ft_size_base(conv.u_int, 10);
		if (conv.s_int < 0)
			i--;
	}
	if (opt.attri.zero)
		print_zero(conv, opt, i);
	else
		print_space(conv, opt, i);
}

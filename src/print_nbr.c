/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:30:19 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/13 17:51:01 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
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
*/
static int	nbrlen(t_conv conv, t_opt opt)
{
	int	len;

	len = ft_size_base(conv.s_int, 10);
	if (opt.presi > len)
		return (opt.presi);
	else
		return (len);
}

static void	print_space(t_conv conv, t_opt opt)
{
	int		size;
	char	ch;

	ch = ' ';
	size = opt.width - nbrlen(conv, opt);
	if (conv.s_int < 0)
		size--;
	if (opt.attri.zero && !opt.attri.moins)
		ch = '0';
	while (size > 0)
	{
		ft_putchar(ch);
		size--;
	}
}

static void	print_pres_zero(t_conv conv, t_opt opt)
{
	int	signe;
	int	size;

	signe = 1;
	size = opt.presi - ft_size_base(conv.s_int, 10);
	if (conv.s_int < 0)
	{
		ft_putchar('-');
		signe = -1;
	}
	while (size > 0)
	{
		ft_putchar('0');
		size--;
	}
}

void	print_nbr(t_conv conv, t_opt opt)
{
	int	signe;

	signe = 1;
	if (conv.s_int < 0)
		signe = -1;
	if (!opt.attri.moins)
		print_space(conv, opt);
	print_pres_zero(conv, opt);
	ft_putnbr(signe * (conv.s_int));
	if (opt.attri.moins)
		print_space(conv, opt);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:30:19 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/13 22:33:55 by jcazako          ###   ########.fr       */
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

static void	print_space_left(t_conv conv, t_opt opt)
{
	int		size;
	char	ch;

	ch = ' ';
	size = opt.width - nbrlen(conv, opt);
	ch = (opt.attri.zero) ? '0' : ' ';
	size = (conv.s_int < 0) ? (size - 1) : size;
	if (ch == '0')
	{
		if (conv.s_int < 0)
			ft_putchar('-');
		else if (opt.attri.plus)
			ft_putchar('+');
	}
	while (size-- > 0 && !opt.attri.moins)
		ft_putchar(ch);
	if (ch == ' ')
	{
		if (conv.s_int < 0)
			ft_putchar('-');
		else if (opt.attri.plus)
			ft_putchar('+');
	}
}

static void	print_pres_zero(t_conv conv, t_opt opt)
{
	int	signe;
	int	size;

	signe = 1;
	size = opt.presi - ft_size_base(conv.s_int, 10);
	if (conv.s_int < 0)
		signe = -1;
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
	size = (conv.s_int < 0) ? (size - 1) : size;
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

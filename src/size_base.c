/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:42:58 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/15 21:42:23 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	change_signe(t_opt *opt)
{
	if (ft_check_charset(opt->type, "di"))
	{
		if (!opt->m_len && (int)opt->conv < 0)
			opt->conv = (int)opt->conv * -1;
		else if (opt->m_len == 'h' && (short)opt->conv < 0)
			opt->conv = (short)opt->conv * -1;
		else if (opt->m_len == 'H' && (char)opt->conv < 0)
			opt->conv = (char)opt->conv * -1;
		else if (ft_check_charset(opt->m_len, "lL") && opt->conv < 0)
			opt->conv *= -1;
	}
	else if (opt->type == 'D' && opt->conv < 0)
		opt->conv *= -1;
}

int	size_base(t_opt opt)
{
	int		i;
	unsigned long	base;

	i = 1;
	if (ft_check_charset(opt.type, "oO"))
		base = 8;
	else if (ft_check_charset(opt.type, "xXp"))
		base = 16;
	else
		base = 10;
	change_signe(&opt);
	if (ft_check_charset(opt.type, "uUxXoOp"))
		while ((unsigned long)opt.conv >= base)
		{
			opt.conv = (unsigned long)opt.conv / base;
			i++;
		}
	else if (opt.type == 'D'|| (ft_check_charset(opt.type, "di")
		&& ft_check_charset(opt.m_len, "lL")))
		while (opt.conv >= (long)base)
		{
			opt.conv /= (long)base;
			i++;
		}
	else if (ft_check_charset(opt.type, "di") && opt.m_len == 'h')
		while ((short)opt.conv >= (short)base)
		{
			opt.conv = (short)opt.conv / (short)base;
			i++;
		}
	else if (ft_check_charset(opt.type, "di") && opt.m_len == 'H')
		while ((char)opt.conv >= (char)base)
		{
			opt.conv = (char)opt.conv / (char)base;
			i++;
		}
	return (i);
}

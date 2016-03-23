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
	if (opt.type == 'o')
		base = 8;
	else if (ft_check_charset(opt.type, "xXp"))
		base = 16;
	else
		base = 10;
	change_signe(&opt);
	if (ft_check_charset(opt.type, "uUxXop"))
		while ((unsigned long)opt.conv >= base)
		{
			opt.conv = (unsigned long)opt.conv / base;
			i++;
		}
	else
		while (opt.conv >= (long)base)
		{
			opt.conv /= (long)base;
			i++;
		}
	return (i);
}

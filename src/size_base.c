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

int	size_base(t_opt opt)
{
	int	i;
	long	base;

	i = 1;
	if (opt.type == 'o')
		base = 8;
	else if (ft_check_charset(opt.type, "xXp"))
		base = 16;
	else
		base = 10;
	if (ft_check_charset(opt.type, "id") && (int)opt.conv < 0)
		opt.conv = (int)opt.conv * -1;
	else if (!ft_check_charset(opt.type, "di") && opt.conv < 0)
		opt.conv *= -1;
	while (opt.conv >= base)
	{
		opt.conv /= base;
		i++;
	}
	return (i);
}

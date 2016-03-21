/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:44:38 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/15 21:57:11 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_str(t_opt opt)
{
	int	size;
	int i;
	int	ret;

	ret = 0;
	size = 0;
	i = 0;
	if (opt.width)
	{
		if (opt.conv)
			size = ft_strlen((char*)opt.conv);
		i = opt.width - size;
	}
	if (!opt.attri.moins)
		while (i--)
		{
			ft_putchar(' ');
			ret++;
		}
	ft_putstr((char*)opt.conv);
	if (opt.conv)
		ret += ft_strlen((const char*)opt.conv);
	if (opt.attri.moins)
		while (i--)
		{
			ft_putchar(' ');
			ret++;
		}
	return (ret);
}

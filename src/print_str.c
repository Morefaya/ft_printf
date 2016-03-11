/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:44:38 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/11 14:55:04 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(t_conv conv, t_opt opt)
{
	int	size;
	int i;

	size = 0;
	i = 0;
	if (opt.width)
	{
		if (conv.s_type)
			size = ft_strlen(conv.s_type);
		i = opt.width - size;
	}
	if (!opt.attri.moins)
		while (i--)
			ft_putchar(' ');
	ft_putstr(conv.s_type);
	if (opt.attri.moins)
		while (i--)
			ft_putchar(' ');
}

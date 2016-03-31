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
#include <wchar.h>

static void	print_space(t_opt opt, int *ret)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	if (opt.width)
	{
		if (opt.conv)
			size = ft_strlen((char*)opt.conv);
		i = opt.width - size;
	}
	while (i--)
	{
		ft_putchar(' ');
		ret++;
	}
}
static int	putlong_str(t_opt *opt)
{
	int	ret;

	ret = 0;
	if (opt->conv)
	{
		ret += putlong_char(*opt);
	}
	return (ret);
}

int		print_str(t_opt opt)
{
	int	ret;

	ret = 0;
	if (!opt.attri.moins)
		print_space(opt, &ret);
	if (opt.type == 'S')
		putlong_str(&opt);
	else
		ft_putstr((char*)opt.conv);
	if (opt.conv)
		ret += ft_strlen((const char*)opt.conv);
	if (opt.attri.moins)
		print_space(opt, &ret);
	return (ret);
}

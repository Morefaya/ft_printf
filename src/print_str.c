/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:44:38 by jcazako           #+#    #+#             */
/*   Updated: 2016/05/17 20:21:37 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

static int	putlong_str(t_opt opt, int cond)
{
	int		ret;
	wchar_t	*str;

	ret = 0;
	str = (int*)opt.conv;
	while (*str)
	{
		opt.conv = *str;
		opt.type = 'C';
		ret += putlong_char(opt, cond);
		str++;
	}
	return (ret);
}

static void	print_space(t_opt opt, int *ret)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	if (opt.width)
	{
		if (ft_check_charset(opt.type, "SC") && opt.conv)
			size = putlong_str(opt, 0);
		else if (opt.conv)
			size = ft_strlen((char*)opt.conv);
		i = opt.width - size;
	}
	while (i-- > 0)
	{
		ft_putchar(' ');
		(*ret)++;
	}
}

int			print_str(t_opt opt)
{
	int	ret;

	ret = 0;
	if (!opt.conv)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (!opt.attri.moins)
		print_space(opt, &ret);
	if (opt.type == 'S' || (opt.type == 's' && opt.m_len == 'l'))
		ret += putlong_str(opt, 1);
	else
	{
		ft_putstr((char*)opt.conv);
		ret += ft_strlen((const char*)opt.conv);
	}
	if (opt.attri.moins)
		print_space(opt, &ret);
	return (ret);
}

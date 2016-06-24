/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:48:08 by jcazako           #+#    #+#             */
/*   Updated: 2016/06/24 20:15:54 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include <wchar.h>
#include <inttypes.h>

static int	get_conv(const char **format, va_list ap, t_opt *opt)
{
	if (ft_check_charset(**format, CONV))
	{
		opt->conv = va_arg(ap, long);
		opt->type = **format;
		return (1);
	}
	else if (**format == '%')
	{
		ft_putchar('%');
		return (2);
	}
	return (0);
}

static void	modify_len(t_opt *opt)
{
	if (ft_check_charset(opt->type, CONV))
	{
		if (ft_check_charset(opt->type, "sSpDUO")
			|| ft_check_charset(opt->m_len, "lLjz"))
			opt->conv &= opt->conv & 0xffffffffffffffff;
		else if (opt->m_len == 'h')
			opt->conv &= opt->conv & 0x000000000000ffff;
		else if (opt->m_len == 'H' || opt->type == 'c')
			opt->conv &= opt->conv & 0x00000000000000ff;
		else
			opt->conv &= opt->conv & 0x00000000ffffffff;
	}
}

static int	print_var(const char **format, va_list ap)
{
	int		ret;
	t_opt	opt;
	int	conv;
	int		i;

	bzero_opt(&opt);
	conv = 0;
	i = 0;
	while (!ft_check_charset(**format, CONV))
	{
		ret = 0;
		if (parse_attr(format, &(opt.attri)))
			ret = 1;
		if (parse_width(format, &opt))
			ret = 1;
		if (parse_pres(format, &opt))
			ret = 1;
		if (ft_check_charset(**format, "lhjz"))
		{
			if (parse_modifier(format, &opt))
				ret = 1;
		}
		if (!ret)
			break ;
	}
	if (!(conv = get_conv(format, ap, &opt)))
	{
		if (opt.width)
		{
			while (i++ < opt.width - 1)
				ft_putchar(' ');
			ret += --i;
		}
		return (ret);
	}
	else if (conv == 2)
		return (1);
	modify_len(&opt);
	ret = print(opt);
	(*format)++;
	return (ret);
}

static void	deal_percent(const char **format, va_list ap, int *ret)
{
	if (**format != '%')
		(*ret) += print_var(format, ap);
	else
	{
		ft_putchar('%');
		(*format)++;
		(*ret)++;
	}
}

int			ft_printf(const char *format, ...)
{
	char	*next_prc;
	int		ret;
	va_list	ap;

	ret = 0;
	va_start(ap, format);
	if (!(ft_strcmp(format, "%")))
		return (0);
	while (*format)
	{
		if ((next_prc = ft_strchr(format, '%')))
		{
			write(1, format, next_prc - format);
			ret += next_prc - format;
			format += next_prc - format + 1;
		}
		else
		{
			ft_putstr(format);
			ret += ft_strlen(format);
			format += ft_strlen(format) + 1;
			break ;
		}
		deal_percent(&format, ap, &ret);
	}
	va_end(ap);
	return (ret);
}

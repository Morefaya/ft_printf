/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:48:08 by jcazako           #+#    #+#             */
/*   Updated: 2016/05/27 18:51:19 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include <wchar.h>
#include <inttypes.h>

static void	get_conv(const char **format, va_list ap, t_opt *opt)
{
	if (ft_check_charset(**format, CONV))
	{
		opt->conv = va_arg(ap, long);
		opt->type = **format;
	}
	else if (**format == '%')
		opt->type = '%';
}

static int	print(t_opt opt)
{
	int		ret;

	ret = 0;
	if (ft_check_charset(opt.type, "pidDoOuUxX"))
		ret += print_nbr(opt);
	else if (opt.type == 's' || opt.type == 'S')
		ret += print_str(opt);
	else if (opt.type == 'c' || opt.type == 'C')
		ret += putlong_char(opt, 1);
	else if (opt.type == '%')
	{
		ft_putchar('%');
		ret++;
	}
	return (ret);
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

	ret = 0;
	bzero_opt(&opt);
	while (!ft_check_charset(**format, CONV))
	{
		parse_attr(format, &(opt.attri));
		parse_width(format, &opt);
		parse_pres(format, &opt);
		if (ft_check_charset(**format, "lhjz"))
			parse_modifier(format, &opt);
	}
	get_conv(format, ap, &opt);
	modify_len(&opt);
	ret = print(opt);
	(*format)++;
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	char	*next_prc;
	int		ret;
	va_list	ap;

	ret = 0;
	va_start(ap, format);
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
		ret += print_var(&format, ap);
	}
	va_end(ap);
	return (ret);
}

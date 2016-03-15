/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 11:30:13 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/15 14:46:26 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

/*static void	ft_printf_1(const char *format, ...)
{
	va_list	ap;
	int	i;

	i = 0;
	va_start(ap, format);
	while (format)
	{
		ft_putendl(format);
		format = va_arg(ap, char*);
	}
	va_end(ap);
}*/

static void	bzero_attr(t_opt *opt)
{
	opt->attri.diez = 0;
	opt->attri.zero = 0;
	opt->attri.moins = 0;
	opt->attri.plus = 0;
	opt->attri.space = 0;
}

static void	bzero_opt(t_opt *opt)
{
	bzero_attr(opt);
	opt->width = 0;
	opt->presi = 0;
	opt->m_len = '\0';
}

static void	get_conv(const char **format, va_list ap, t_opt *opt)
{
	if (ft_check_charset(**format, CONV))
		opt->type = **format;
	else if (**format == '%')
		opt->type = '%';
	if (opt->type == 'd' || opt->type == 'i')
		opt->conv.s_int = va_arg(ap, int);
	else if (opt->type == 'o' || opt->type == 'u'
		|| opt->type == 'x' || opt->type == 'X')
		opt->conv.u_int = va_arg(ap, unsigned int);
	else if (opt->type == 's' || opt->type == 'S')
		opt->conv.s_type = va_arg(ap, const char*);
	else if (opt->type == 'p')
		opt->conv.v_type = va_arg(ap, void*);
	else if (opt->type == 'c' || opt->type == 'C')
		opt->conv.c_type = (unsigned char)va_arg(ap, int);
}

static int	print(t_opt opt)
{
	int		ret;

	ret = 0;
	if (opt.type == 'd' || opt.type == 'i')
		ret += print_nbr(opt.conv, opt);
	else if (opt.type == 'o' || opt.type == 'u'
		|| opt.type == 'x' || opt.type == 'X')
		ft_putnbr(opt.conv.u_int);
	else if (opt.type == 's' || opt.type == 'S')
		ret += print_str(opt.conv, opt);
	else if (opt.type == 'p')
		ft_putnbr(opt.conv.s_int);
	else if (opt.type == 'c' || opt.type == 'C')
	{
		ft_putchar(opt.conv.c_type);
		ret++;
	}
	else if (opt.type == '%')
	{
		ft_putchar('%');
		ret++;
	}
	return (ret);
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
	}
	get_conv(format, ap, &opt);
	ret = print(opt);
	(*format)++;
	return (ret);
}

static int	ft_printf_2(const char *format, ...)
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
			break;
		}
		ret += print_var(&format, ap);
	}
	va_end(ap);
	return (ret);
}

int	main(void)
{
	char	*str = "hello  %- 12.2+17.5d its %  d chinese: %-14s\n";
	int		ret_ft = ft_printf_2(str, -789, 456, "畢竟");
	int		ret_pf = printf(str, -789, 456, "畢竟");
	printf("returns: -ft %d\t-pf %d\n", ret_ft, ret_pf);
	/*ft_printf_1("hello", "its", "me", "I", "was", "wondering", NULL);*/
	return (0);
}

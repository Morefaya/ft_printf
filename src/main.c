/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 11:30:13 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/15 12:05:20 by jcazako          ###   ########.fr       */
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

static void	get_type(const char **str, va_list ap)
{
	t_conv	tmp;
	t_opt	opt;

	bzero_opt(&opt);
	while (!ft_check_charset(**str, CONV))
	{
		parse_attr(str, &(opt.attri));
		parse_width(str, &opt);
		parse_pres(str, &opt);
	}
	if (**str == 'd' || **str == 'i')
	{
		tmp.s_int = va_arg(ap, int);
		print_nbr(tmp, opt);
	}
	else if (**str == 'o' || **str == 'u' || **str == 'x' || **str == 'X')
	{
		tmp.u_int = va_arg(ap, unsigned int);
		ft_putnbr(tmp.u_int);
	}
	else if (**str == 's' || **str == 'S')
	{
		tmp.s_type = va_arg(ap, const char*);
		print_str(tmp, opt);
	}
	else if (**str == 'p')
	{
		tmp.v_type = va_arg(ap, void*);
		ft_putnbr((int)tmp.v_type);
	}
	else if (**str == 'c' || **str == 'C')
	{
		tmp.c_type = (unsigned char)va_arg(ap, int);
		ft_putchar(tmp.c_type);
	}
	else if (**str == '%')
		ft_putchar('%');
	(*str)++;
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
		get_type(&format, ap);
	}
	va_end(ap);
	return (ret);
}

int	main(void)
{
	char *str = "hello %- 12.2+17.5d its %  d I was wondering if %-14s all this\n";

	ft_printf_2(str, -789, 456, "after");
	printf(str, -789, 456, "@fter");
	/*ft_printf_1("hello", "its", "me", "I", "was", "wondering", NULL);*/
	return (0);
}

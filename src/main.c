/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 11:30:13 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/05 16:51:12 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

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

static void	get_type(const char *str, va_list ap)
{
	t_conv	tmp;

	if (*str == 'd' || *str == 'i')
	{
		tmp.s_int = va_arg(ap, int);
		ft_putnbr(tmp.s_int);
	}
	else if (*str == 'o' || *str == 'u' || *str == 'x' || *str == 'X')
	{
		tmp.u_int = va_arg(ap, unsigned int);
		ft_putnbr(tmp.u_int);
	}
	else if (*str == 's' || *str == 'S')
	{
		tmp.s_type = (char*)va_arg(ap, const char*);
		ft_putstr(tmp.s_type);
	}
	else if (*str == 'p')
	{
		tmp.v_type = va_arg(ap, void*);
		ft_putnbr((int)tmp.v_type);
	}
	else if (*str == 'c' || *str == 'C')
	{
		tmp.c_type = (unsigned char)va_arg(ap, int);
		ft_putchar(tmp.c_type);
	}
}

static int	ft_printf_2(const char *format, ...)
{
	char	*next_prc;
	int	ret;
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
		get_type(format, ap);
	}
	va_end(ap);
	ft_putchar('\n');
	return (ret);
}

int	main(void)
{
	char *str = "hello %d its me %d i was wondering if after %s all";

	ft_putnbr(ft_printf_2(str, 123, 456, "kicking my ass"));
	ft_putchar('\t');
	ft_putnbr(ft_strlen(str));
	ft_putchar('\n');
	ft_putnbr(sizeof(int64_t));
	ft_putchar('\n');
	/*printf("%p\n", str);
	ft_printf_1("hello", "its", "me", "I", "was", "wondering", NULL);*/
	return (0);
}

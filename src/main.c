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
		tmp.c = va_arg(ap, int);
		ft_putnbr(tmp.c);
	}
	else if (*str == 'o' || *str == 'u' || *str == 'x' || *str == 'X')
	{
		tmp.g = va_arg(ap, char*);
		ft_putstr(tmp.g);
	}
	else if (*str == 'e' || *str == 'E')
	{
		
	}
	else if (*str == 'f' || *str == 'F')
	{

	}
	else if (*str == 'g' || *str == 'G')
	{

	}
	else if (*str == 'a' || *str == 'A')
	{

	}
	else if (*str == 's' || *str == 'S')
	{

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
	/*printf("%p\n", str);
	ft_printf_1("hello", "its", "me", "I", "was", "wondering", NULL);*/
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_attr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 11:00:00 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/11 14:22:57 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	bzero_attr(t_attr *attr)
{
	attr->diez = 0;
	attr->zero = 0;
	attr->moins = 0;
	attr->plus = 0;
	attr->space = 0;
}

static void	init_attr(const char *format, t_attr *attr)
{
	if (*format == '#')
		attr->diez = 1;
	else if (*format == '0')
		attr->zero = 1;
	else if (*format == '-')
		attr->moins = 1;
	else if (*format == '+')
		attr->plus = 1;
	else if (*format == ' ')
		attr->space = 1;
}

void	get_attrib(const char **format, t_attr *attr)
{
	bzero_attr(attr);
	while (ft_check_charset((char)(**format), ATTR))
	{
		init_attr(*format, attr);
		(*format)++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pres.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:12:11 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/13 18:38:49 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	deal_pres(const char **format, t_opt *opt, va_list ap)
{
	int		pres;
	int		i_pres;
	va_list	ap_cp;

	va_copy(ap_cp, ap);
	i_pres = 0;
	pres = 0;
	(*format)++;
	if (ft_check_charset(**format, "123456789"))
	{
		i_pres = ft_atoi(*format);
		while (i_pres > 0)
		{
			pres = va_arg(ap_cp, int);
			i_pres--;
		}
		opt->presi = pres;
	}
	else
		opt->presi = va_arg(ap_cp, int);
	va_end(ap_cp);
}

void		parse_pres(const char **format, t_opt *opt, va_list ap)
{
	int	pres;
	int	tmp;

	pres = 0;
	tmp = 0;
	if (**format == '.')
		(*format)++;
	if (ft_check_charset(**format, "-123456789"))
	{
		pres = ft_atoi(*format);
		tmp = pres;
		if (pres < 0)
		{
			tmp *= -1;
			pres = 0;
		}
		opt->presi = pres;
		(*format) += ft_size_base(tmp, 10);
	}
	else if (**format == '*')
		deal_pres(format, opt, ap);
	else
		opt->presi = 0;
}

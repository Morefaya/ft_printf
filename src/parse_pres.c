/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pres.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:12:11 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/13 20:53:53 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_pres(const char **format, t_opt *opt)
{
	int	pres;
	int	tmp;

	pres = 0;
	tmp = 0;
	if (**format == '.')
		(*format)++;
	if (ft_check_charset(**format, "-1234567890"))
	{
		pres = ft_atoi(*format);
		tmp = pres;
		if (pres < 0)
		{
			tmp *= -1;
			pres = 0;
		}
		opt->presi = pres;
		if (**format == '-')
			(*format)++;
		while (ft_check_charset(**format, "1234567890"))
			(*format)++;
	}
}

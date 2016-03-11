/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 11:42:37 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/11 14:18:34 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width(const char **format, t_opt *opt)
{
	int	width;

	width = 0;
	width = ft_atoi(*format);
	/*if (width < 0)
	{
		opt->attri.moins = 1;
		width *= -1;
	}*/
	opt->width = width;	
	(*format) += ft_size_base(width, 10);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 14:49:10 by jcazako           #+#    #+#             */
/*   Updated: 2016/05/30 14:49:17 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print(t_opt opt)
{
	int		ret;

	ret = 0;
	if (ft_check_charset(opt.type, "pidDoOuUxX"))
		ret += print_nbr(opt);
	else if (opt.type == 's' || opt.type == 'S')
		ret += print_str(opt);
	else if (opt.type == 'c' || opt.type == 'C')
		ret += putlong_char(opt, 1);
	return (ret);
}

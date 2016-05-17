/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putshort_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 21:11:16 by jcazako           #+#    #+#             */
/*   Updated: 2016/05/17 21:11:19 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putshort_nbr(short nbr)
{
	if (nbr < 0)
		nbr *= -1;
	if (nbr > 9)
	{
		putshort_nbr(nbr / 10);
		putshort_nbr(nbr % 10);
	}
	else
		ft_putchar('0' + nbr);
}

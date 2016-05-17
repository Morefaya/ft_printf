/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlong_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 21:20:33 by jcazako           #+#    #+#             */
/*   Updated: 2016/05/17 22:09:51 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	putlong_base(long nbr, char *base)
{
	int	len;
	int	nb_u;

	len = ft_strlen(base);
	nb_u = nb;
	if (nb_u > len - 1)
	{
		putlong_base(nb_u / len, base);
		putlong_base(nb_u % len, base);
		return ;
	}
	ft_putchar(base[nb_u]);
	return ;
}

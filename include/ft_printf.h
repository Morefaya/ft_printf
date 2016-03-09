/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:25:50 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/05 14:35:31 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef union		u_conv
{
	char		c_type;
	int		s_int;
	unsigned int	u_int;
	long		l_type;
	float		f_type;
	double		d_type;
	char		*s_type;
	void		*v_type;
}			t_conv;

typedef struct		s_opt
{
	int		attri;
	int		width;
	int		presi;
	int		m_len;
}			t_opt;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:25:50 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/14 22:17:11 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define ATTR "#0-+ "
# define CONV "sSpdDioOuUxXcC"

typedef union		u_conv
{
	char			c_type;
	int				s_int;
	unsigned int	u_int;
	long			l_type;
	float			f_type;
	double			d_type;
	const char		*s_type;
	void			*v_type;
}					t_conv;

typedef struct		s_attr
{
	int				diez;
	int				zero;
	int				moins;
	int				plus;
	int				space;
}					t_attr;

typedef struct		s_opt
{
	t_attr			attri;
	int				width;
	int				presi;
	char			m_len;
}					t_opt;

void				parse_attr(const char **str, t_attr *att);
void				parse_width(const char **format, t_opt *opt);
void				print_nbr(t_conv conv, t_opt opt);
void				print_str(t_conv conv, t_opt opt);
void				parse_pres(const char **format, t_opt *opt);

#endif

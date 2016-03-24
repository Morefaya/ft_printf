/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:25:50 by jcazako           #+#    #+#             */
/*   Updated: 2016/03/24 20:36:16 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define ATTR "#0-+ "
# define CONV "sSpdDioOuUxXcC"
# define U_MASK_0 0
# define U_MASK_1 49280
# define U_MASK_2 29393024
# define U_MASK_3 16114548864

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
	char			type;
	long			conv;
}					t_opt;

int					size_base(t_opt opt);
int					putlong_char(t_opt opt);

void				putlong_nbr(long nbr, t_opt opt);
void				putlun_nbr(unsigned long nbr, t_opt opt);
void				putshort_nbr(short nbr);
void				putchar_nbr(char nbr);

void				parse_attr(const char **str, t_attr *att);
void				parse_width(const char **format, t_opt *opt);

void				parse_modifier(const char **format, t_opt *opt);

int					print_nbr(t_opt opt);
int					print_str(t_opt opt);
void				parse_pres(const char **format, t_opt *opt);

int					print_space_left(t_opt opt);
int					print_zero_left(t_opt opt, int cond);
int					print_prefix(t_opt opt, int cond);
int					nbrlen(t_opt opt);
int					check_signe_moins(t_opt opt);
#endif

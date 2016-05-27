/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:25:50 by jcazako           #+#    #+#             */
/*   Updated: 2016/05/27 18:47:30 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define ATTR "#0-+ "
# define CONV "sSpdDioOuUxXcC"
# define MASK_0	0x7F
# define MASK_1 0x1F3F
# define MASK_2 0xF3F3F
# define MASK_3 0x73F3F3F
# define U_MASK_0 0x0
# define U_MASK_1 0xC080
# define U_MASK_2 0xE08080
# define U_MASK_3 0xF0808080

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
int					putlong_char(t_opt opt, int cond);

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

int					check_signe_moins(t_opt opt);
int					nbrlen(t_opt opt);
int					print_prefix(t_opt opt, int cond);
void				change_signe(t_opt *opt);
void				print_c(long ret);

int					atoi_base(char *str, char *base);
void				putint_base(int nbr, char *base);

int					szb_ul(t_opt opt, unsigned long base);
int					szb_l(t_opt opt, unsigned long base);
int					szb_s(t_opt opt, unsigned long base);
int					szb_c(t_opt opt, unsigned long base);
int					szb_i(t_opt opt, unsigned long base);

void				bzero_attr(t_opt *opt);
void				bzero_opt(t_opt *opt);
int					ft_printf(const char *format, ...);
#endif

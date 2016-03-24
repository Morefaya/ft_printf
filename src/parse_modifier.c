#include "ft_printf.h"

void     parse_modifier(const char **format, t_opt *opt)
{
        if (**format == 'l')
        {
		if (opt->m_len == 'l')
			opt->m_len = 'L';
		else
			opt->m_len = 'l';
        }
        else if (**format == 'h')
        {
		if (opt->m_len == 'h')
			opt->m_len = 'H';
		else if (opt->m_len == 'H' || !opt->m_len)
			opt->m_len = 'h';
        }
        else if (**format == 'j')
                opt->m_len = 'j';
        else if (**format == 'z')
                opt->m_len = 'z';
        (*format)++;
}

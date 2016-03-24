#include "ft_printf.h"

static void	parse_l(const char **format, t_opt *opt)
{
	int	i;

	i = 1;
	if (!ft_check_charset(**format, "lhjz"))
		return ;
	if (**format == 'l')
	{
		while (!ft_check_charset(*(*format + i), CONV))
		{
			if (*(*format + i) == 'l')
			{
				opt->m_len = 'L'
			}
			i++;
		}
	}
}

void     parse_modifier(const char **format, t_opt *opt)
{
        if (**format == 'l')
        {
                if (*(*format + 1) == 'l')
                {
                        opt->m_len = 'L';
                        (*format)++;
                }
                else
                        opt->m_len = 'l';
        }
        else if (**format == 'h')
        {
                if (*(*format + 1) == 'h')
                {
                        opt->m_len = 'H';
                        (*format)++;
                }
                else
                        opt->m_len = 'h';
        }
        else if (**format == 'j')
                opt->m_len = 'j';
        else if (**format == 'z')
                opt->m_len = 'z';
        (*format)++;
}

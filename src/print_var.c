

#include "ft_printf.h"
#include <unistd.h>

static int	print_var(const char **format, va_list ap)
{
	int		ret;
	t_opt	opt;
	int	conv;
	int		i;

	bzero_opt(&opt);
	conv = 0;
	i = 0;
	while (!ft_check_charset(**format, CONV))
	{
		ret = 0;
		if (parse_attr(format, &(opt.attri)))
			ret = 1;
		if (parse_width(format, &opt))
			ret = 1;
		if (parse_pres(format, &opt))
			ret = 1;
		if (ft_check_charset(**format, "lhjz"))
		{
			if (parse_modifier(format, &opt))
				ret = 1;
		}
		if (!ret)
			break ;
	}
	if (!(conv = get_conv(format, ap, &opt)))
	{
		if (opt.width && !opt.attri.moins)
		{
			while (i++ < opt.width - 1)
			{
				if (!opt.pres_on)
					ft_putchar(' ');
				else
					ft_putchar('0');
			}
			ret += --i;
		}
		ft_putchar(**format);
		if (opt.width && opt.attri.moins)
		{
			while (i++ < opt.width - 1)
			{
				if (!opt.pres_on)
					ft_putchar(' ');
				else
					ft_putchar('0');
			}
			ret += --i;
		}
		ret++;
		(*format)++;
		return (ret);
	}
	modify_len(&opt);
	ret = print(opt);
	(*format)++;
	return (ret);
}

static void	deal_percent(const char **format, va_list ap, int *ret)
{
	if (**format != '%')
		(*ret) += print_var(format, ap);
	else
	{
		ft_putchar('%');
		(*format)++;
		(*ret)++;
	}
}

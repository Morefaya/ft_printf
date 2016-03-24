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

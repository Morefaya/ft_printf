#include "ft_printf.h"

void	putnbr(int nbr, int *ret)
{
	if (nbr == INT_MIN)
	{
		ft_putstr("2147483648");
		(*ret) += 10;
		return ;
	}
	if (nbr > 9)
	{
		putnbr(nbr / 10, ret);
		putnbr(nbr % 10, ret);
	}
	else
	{
		ft_putchar('0' + nbr);
		(*ret)++;
	}
}

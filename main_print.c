#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	i = 0;
	i = ft_printf("%hhC, %hhC", 0, L'米');
	printf("\n %d", i);
	//putlong_nbr(L'米', &i);
	return (0);
}

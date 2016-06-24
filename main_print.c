#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	i = 0;
	i = printf("%.i, %.0i", 1, 0);
	printf("\n %d", i);
	//putlong_nbr(L'米', &i);
	return (0);
}

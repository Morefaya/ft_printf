#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	i = 0;
	int	j = 0;
	i = ft_printf("%hhC, %hhC", 0, L'米');
	ft_putchar('\n');
	j = printf("%hhC, %hhC", 0, L'米');
	printf("\nft_printf return: %d\nprintf return: %d\n", i, j);
	//putlong_nbr(L'米', &i);
	return (0);
}

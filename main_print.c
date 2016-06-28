#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	i = 0;
	int	j = 0;
	i = ft_printf("%03.2d", 0);
	ft_putchar('\n');
	j = printf("%03.2d", 0);
	printf("\nft_printf return: %d\nprintf return: %d\n", i, j);
	return (0);
}

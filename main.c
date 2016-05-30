#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ret_f = ft_printf("%%   %d\t", 1);
	int	ret_p = printf("%%   %d\n", 1);
	
	printf("%d\t%d\n", ret_f, ret_p);
	return (0);
}

void	ft_putint_base(int nb, char *base);
int	ft_pow(int nb, int pow);
void	ft_putint(int nb);
void	ft_putchar(char a);

int	main(void)
{
	int i;
	char base[] ="0123456789ABCDEF";

	i = 31;
	ft_putint(-1);
	ft_putchar('\t');
	ft_putint_base(-1, base);
	ft_putchar('\n');
	return (0);
}

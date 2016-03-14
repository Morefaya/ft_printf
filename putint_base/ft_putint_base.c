int	ft_strlen(char *str);
void	ft_putchar(char a);
int	check_base(char *base);

void	ft_putint_base(int nb, char *base)
{
	unsigned int len;
	unsigned int nb_u;

	len = ft_strlen(base);
	nb_u = nb;
	if (check_base(base))
	{
		return;
	}
	if (nb_u  > len - 1)
	{
		ft_putint_base(nb_u / len, base);
		ft_putint_base(nb_u % len, base);
		return;
	}
	ft_putchar(base[nb_u]);
	return;
}

void	ft_putchar(char a);

void	ft_putint(int nb)
{
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_putint(nb / 10);
		ft_putint(nb % 10);
		return ;
	}
	ft_putchar(nb + '0');
	return ;
}

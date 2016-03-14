int	ft_pow(int nb, int pow)
{
	int result;
	
	result = 1;
	while(pow)
	{
		result *= nb;
		pow--;
	}
	return (result);
}

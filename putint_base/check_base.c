unsigned int	ft_strlen(char *str);

int	check_base_double(char *base)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (base[i])
	{
		j = i + 1;
		while(base[j])
		{
			if (base[i] == base[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_base_size(char *base)
{
	if (ft_strlen(base) < 2)
	{
		return (1);
	}
	return (0);
}

int	check_char_forbidden(char *base, char *forbidden)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (forbidden[i])
	{
		j = 0;
		while (base[j])
		{
			if (forbidden[i] == base[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_base(char *base)
{
	if (check_base_double(base))
	{
		return (1);
	}
	if (check_base_size(base))
	{
		return (1);
	}
	if (check_char_forbidden(base, "+-/*%"))
	{
		return (1);
	}
	return (0);
}

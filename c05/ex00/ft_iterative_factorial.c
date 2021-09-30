int	ft_iterative_factorial(int nb)
{
	int	fakt;

	fakt = 1;
	if (nb < 0 || nb > 12)
		return (0);
	while (nb > 0)
	{
		fakt = fakt * nb;
		nb--;
	}
	return (fakt);
}

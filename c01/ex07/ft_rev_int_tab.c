void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	rvs;

	i = 0;
	while (i < size / 2)
	{
		rvs = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = rvs;
		i++;
	}
}

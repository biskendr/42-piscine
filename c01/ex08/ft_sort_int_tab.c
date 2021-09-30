void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	ksayi;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				ksayi = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = ksayi;
			}
			j++;
		}
		i++;
	}
}

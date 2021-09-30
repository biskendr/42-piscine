void	ft_putchar(char n);
void	rush(int x, int y)
{
	int	v;
	int	h;

	v = 0;
	while (v++ < y)
	{
		h = 0;
		while (h++ < x)
		{
			if ((h == 1 && v == 1) || (h == 1 && v == y))
				ft_putchar('A');
			else if ((h == x && v == 1) || (h == x && v == y))
				ft_putchar('C');
			else if ((h == 1) || (h == x) || (v == 1) || (v == y))
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

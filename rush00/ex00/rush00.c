void	ft_putchar(char c);
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
			if ((v == 1 || v == y) && (h == 1 || h == x))
				ft_putchar('o');
			else if ((h != 1 || h != x) && (v == 1 || v == y))
				ft_putchar('-');
			else if ((h == 1 || h == x) && (v != 1 || v != y))
				ft_putchar('|');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

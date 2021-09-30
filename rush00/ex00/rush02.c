void	ft_putchar(char n);
void	rush(int x, int y)
{
	int	a;
	int	d;

	d = 1;
	while (d <= y && x > 0)
	{
		a = 1;
		while (a <= x)
		{
			if ((a == 1 && d == 1) || (a == x && d == 1))
				ft_putchar('A');
			else if ((a == x && d == y) || (a == 1 && d == y))
				ft_putchar('C');
			else if ((a == 1) || (a == x) || (d == 1) || (d == y))
				ft_putchar('B');
			else
				ft_putchar(' ');
			a++;
		}
		ft_putchar('\n');
		d++;
	}
}

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	bolum;
	int	kalan;

	bolum = *a / *b;
	kalan = *a % *b;
	*a = bolum;
	*b = kalan;
}

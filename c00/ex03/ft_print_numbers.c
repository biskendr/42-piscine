#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	char	rakam;

	rakam = '0';
	while (rakam <= '9')
	{
		ft_putchar(rakam);
		rakam++;
	}
}

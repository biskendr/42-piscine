#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	char	harf;

	while (*str)
	{
		harf = *str;
		if (harf == '\0')
			break ;
		ft_putchar(harf);
		str++;
	}
}

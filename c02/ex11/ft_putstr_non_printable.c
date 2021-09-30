#include <stdbool.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

bool	is_char_printable(char c)
{
	return (c >= ' ' && c != 127);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	input;

	i = 0;
	while (true)
	{
		input = str[i];
		if (input == '\0')
			break ;
		if (is_char_printable(input))
			ft_putchar(input);
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[input / 16]);
			ft_putchar("0123456789abcdef"[input % 16]);
		}
		i++;
	}
}

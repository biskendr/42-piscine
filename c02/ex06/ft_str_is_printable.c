#include <stdbool.h>

int	ft_str_is_printable(char *str)
{
	int		i;
	bool	check;
	char	input;

	i = 0;
	check = true;
	while (true)
	{
		input = str[i];
		if (input == '\0')
			break ;
		if (!(input >= ' ') || input == 127)
		{
			check = false;
			break ;
		}
		i++;
	}
	return (check);
}

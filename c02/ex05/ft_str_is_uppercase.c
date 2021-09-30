#include <stdbool.h>

int	ft_str_is_uppercase(char *str)
{
	int		i;
	bool	check;
	char	letter;

	i = 0;
	check = true;
	while (true)
	{
		letter = str[i];
		if (letter == '\0')
			break ;
		if (!(letter >= 'A' && letter <= 'Z'))
		{
			check = false;
			break ;
		}
		i++;
	}
	return (check);
}

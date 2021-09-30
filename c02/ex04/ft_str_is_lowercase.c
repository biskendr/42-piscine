#include <stdbool.h>

int	ft_str_is_lowercase(char *str)
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
		if (!(letter >= 'a' && letter <= 'z'))
		{
			check = false;
			break ;
		}
		i++;
	}
	return (check);
}

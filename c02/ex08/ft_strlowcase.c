#include <stdbool.h>

char	*ft_strlowcase(char *str)
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
		if (input >= 'A' && input <= 'Z')
			str[i] = input + 32;
		i++;
	}
	return (str);
}

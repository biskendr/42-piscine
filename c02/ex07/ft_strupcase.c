#include <stdbool.h>

char	*ft_strupcase(char *str)
{
	int		i;
	char	input;

	i = 0;
	while (true)
	{
		input = str[i];
		if (input == '\0')
			break ;
		if (input >= 'a' && input <= 'z')
			str[i] = input - 32;
		i++;
	}
	return (str);
}

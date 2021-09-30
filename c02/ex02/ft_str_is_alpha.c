#include <stdbool.h>

int	ft_str_is_alpha(char *str)
{
	int		i;
	bool	check;
	char	let;

	i = 0;
	check = true;
	while (true)
	{
		let = str[i];
		if (let == '\0')
			break ;
		if (!((let >= 'A' && let <= 'Z') || (let >= 'a' && let <= 'z')))
		{
			check = false;
			break ;
		}
		i++;
	}
	return (check);
}

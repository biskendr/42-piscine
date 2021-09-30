#include <stdbool.h>

int	ft_str_is_numeric(char *str)
{
	int		i;
	bool	check;
	char	num;

	i = 0;
	check = true;
	while (true)
	{
		num = str[i];
		if (num == '\0')
			break ;
		if (!(num >= '0' && num <= '9'))
		{
			check = false;
			break ;
		}
		i++;
	}
	return (check);
}

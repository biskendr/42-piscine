#include <stdio.h>
#include <limits.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (0 < nb)
	{
		while (nb)
		{
			if (nb == i * i)
				return (i);
			else if (i >= 46341)
				return (0);
			i++;
		}
	}
	return (0);
}

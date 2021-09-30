#include <unistd.h>

void	ft_combn(int nb)
{
	char	ch[11];
	int		i;
	int		byte;

	*ch = '0';
	i = 0;
	while (i++ < nb)
		ch[i] = ch[i - 1] + 1;
	ch[nb] = ',';
	ch[nb + 1] = ' ';
	while (*ch <= 58 - nb)
	{
		if (*ch != 58 - nb)
			byte = 2;
		else
			byte = 0;
		write (1, ch, nb + byte);
		i = nb;
		while (i--)
			if (++ch[i] <= 58 - nb + i)
				break ;
		while (++i > 0 && i < nb)
			ch[i] = ch[i - 1] + 1;
	}
}

void	ft_print_combn(int nb)
{
	if(0 < nb && nb < 10)
		ft_combn(nb);
	else
		return ;
}

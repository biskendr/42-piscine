#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*g_text;
char	*g_tut;
int		g_text_i = 0;
char	*g_content;

char	*read_file(char *file)
{
	short			dictfile;
	static char		file_content[1000];
	unsigned short	last_buff;

	dictfile = open(file, O_RDONLY);
	if (dictfile < 0)
	{
		write(1, "dict file not found.\n", 21);
		exit(1);
	}
	last_buff = read(dictfile, file_content, 999);
	file_content[last_buff] = '\0';
	close(dictfile);
	return (file_content);
}

char	*get(char *number)
{
	static char			*n;
	unsigned short int	len;
	unsigned short int	count;
	unsigned short int	c;
	unsigned short int	i;

	len = 0;
	count = 0;
	c = 0;
	i = 0;
	n = malloc(200 * sizeof(char));
	while (number[len] != '\0')
		len++;
	while (g_content[c] != '\0')
	{
		i = 0;
		while (number[i] != '\0')
		{
			if (number[i] == g_content[c])
			{
				c++;
				count++;
			}
			else
			{
				count = 0;
				break ;
			}
			i++;
		}
		if (count == len && g_content[c] == ':' && (g_content[c - count - 1] == '\n' || number[0] == '0'))
		{
			c += 2;
			i = 0;
			while (g_content[c] != '\n')
			{
				n[i] = g_content[c];
				i++;
				c++;
			}
			n[i] = '\0';
			break ;
		}
		c++;
	}
	return (n);
}

void	p(char *s)
{
	char	*g;

	if (*s == ' ')
	{
		g_text[g_text_i] = ' ';
		g_text_i++;
	}
	else
	{
		g = get(s);
		while (*g != '\0')
		{
			g_text[g_text_i] = *g;
			g++;
			g_text_i++;
		}
	}
}

char	*conv(int n)
{
	int	n_temp;
	int	basamak;
	int	bas;
	int	yuzluk;
	int	onluk;
	int	birlik;

	n_temp = n;
	basamak = 0;
	while (n_temp != 0)
	{
		n_temp /= 10;
		basamak++;
	}
	if (n == 0)
		basamak = 1;
	while (basamak > 0)
	{
		if (basamak == 3)
		{
			bas = n / 100;
			if (n > 0)
			{
				g_tut[0] = bas + '0';
				g_tut[1] = '\0';
				p(g_tut);
				p(" ");
				p("100");
			}
		}
		else if (basamak == 2)
		{
			yuzluk = n - (n % 100);
			onluk = n - yuzluk;
			birlik = onluk % 10;
			if (onluk > 19)
			{
				onluk -= birlik;
				p(" ");
				g_tut[0] = onluk / 10 + '0';
				g_tut[1] = '0';
				g_tut[2] = '\0';
				p(g_tut);
				p(" ");
				g_tut[0] = birlik + '0';
				g_tut[1] = '\0';
				p(g_tut);
			}
			else
			{
				if (onluk > 0)
				{
					if (onluk < 10)
					{
						g_tut[0] = onluk + '0';
						g_tut[1] = '\0';
					}
					else
					{
						g_tut[0] = '1';
						g_tut[1] = onluk % 10 + '0';
						g_tut[2] = '\0';
					}
					p(" ");
					p(g_tut);
				}
			}
		}
		else if (basamak == 1)
		{
			g_tut[0] = n + '0';
			g_tut[1] = '\0';
			p(g_tut);
		}
		basamak--;
	}
	return (" ");
}

int	main(int argc, char **argv)
{
	int		arg_i;
	char	*sayi;
	int		argv_i;
	int		sayi2_i;
	char	*sayi2;
	int		ss;
	int		last_zero;
	int		sayi_basamak;
	int		grup_sayisi;
	int		enbas;
	int		cevir;
	int		sayi_i;
	int		g_tut_i;
	int		don;
	int		yaz_i;

	g_text = malloc(sizeof(char) * 300);
	g_tut = malloc(sizeof(char) * 100);
	sayi = malloc(sizeof(char) * 50);
	if (argc == 2)
	{
		argv_i = 1;
		g_content = read_file("numbers.dict");
	}
	else if (argc == 3)
	{
		argv_i = 2;
		g_content = read_file(argv[1]);
	}
	arg_i = 0;
	while (argv[argv_i][arg_i] != '\0')
	{
		if (argv[argv_i][arg_i] < '0' || argv[argv_i][arg_i] > '9')
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		else
		{
			sayi[arg_i] = argv[argv_i][arg_i];
		}
		arg_i++;
	}
	sayi[arg_i] = '\0';
	sayi2_i = 0;
	sayi2 = malloc(50 * sizeof(char));
	ss = 0;
	last_zero = 0;
	while (sayi[ss] != '\0')
	{
		if (sayi[ss] != '0')
			last_zero = 1;
		if (last_zero == 1)
		{
			sayi2[sayi2_i] = sayi[ss];
			sayi2_i++;
		}
		ss++;
	}
	if (last_zero == 0)
	{
		sayi2[0] = '0';
		sayi2[1] = '\0';
	}
	else
	{
		sayi2[sayi2_i] = '\0';
	}
	sayi_basamak = 0;
	while (sayi2[sayi_basamak] != '\0')
		sayi_basamak++;
	grup_sayisi = sayi_basamak / 3;
	if (sayi_basamak % 3 != 0)
		grup_sayisi++;
	enbas = sayi_basamak - (grup_sayisi - 1) * 3;
	cevir = 0;
	sayi_i = 0;
	while (grup_sayisi > 0)
	{
		if (enbas == 1)
		{
			cevir = sayi2[sayi_i] - '0';
			conv(cevir);
			sayi_i++;
		}
		else if (enbas == 2)
		{
			cevir = (sayi2[sayi_i] - '0') * 10 + (sayi2[sayi_i + 1] - '0');
			conv(cevir);
			sayi_i += 2;
		}
		else
		{
			cevir = ((sayi2[sayi_i] - '0') * 100) + ((sayi2[sayi_i + 1] - '0') * 10) + ((sayi[sayi_i + 2] - '0'));
			conv(cevir);
			sayi_i += 3;
		}
		enbas = 0;
		if (grup_sayisi > 1)
		{
			g_tut_i = 0;
			g_tut[g_tut_i] = '1';
			g_tut_i++;
			don = (grup_sayisi - 1) * 3;
			while (don > 0)
			{
				g_tut[g_tut_i] = '0';
				g_tut_i++;
				don--;
			}
			g_tut[g_tut_i] = '\0';
			p(" ");
			p(g_tut);
			p(" ");
		}
		grup_sayisi--;
	}
	yaz_i = 0;
	while (g_text[yaz_i] != '\0')
	{
		write(1, &g_text[yaz_i], 1);
		yaz_i++;
	}
	free(g_text);
	free(g_tut);
	return (0);
}

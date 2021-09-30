int	ft_strlen(char *str)
{
	int	uzunluk;

	uzunluk = 0;
	while (*(str++) != '\0')
		uzunluk++;
	return (uzunluk);
}

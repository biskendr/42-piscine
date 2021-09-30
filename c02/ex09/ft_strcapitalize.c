char	*ft_strcapitalize(char *str)
{
	int		i;
	char	let;
	int		space;

	i = 0;
	while (str[i] != '\0')
	{
		space = 1;
		if (i == 0)
			let = ';';
		else
			let = str[i - 1];
		if ((let >= 'A' && let <= 'Z') || (let >= 'a' && let <= 'z'))
			space = 0;
		if (let >= '0' && let <= '9')
			space = 0;
		if (space == 1 && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		if (space == 0 && str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

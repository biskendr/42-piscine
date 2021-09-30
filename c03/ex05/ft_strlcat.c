unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;

	x = 0;
	y = 0;
	i = 0;
	while (dest[x] != '\0')
		x++;
	while (src[i] != '\0')
		i++;
	if (size <= x)
		i += size;
	else
		i += x;
	while (src[y] != '\0' && (x + 1) < size)
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	dest[x] = '\0';
	return (i);
}

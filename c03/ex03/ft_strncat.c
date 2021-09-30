char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*cpy;

	cpy = dest;
	while (*cpy != '\0')
		cpy++;
	while (*src != '\0' && nb > 0)
	{
		*cpy = *(unsigned char *)src;
		cpy++;
		src++;
		nb--;
	}
	*cpy = '\0';
	return (dest);
}

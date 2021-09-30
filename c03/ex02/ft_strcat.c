char	*ft_strcat(char *dest, char *src)
{
	char	*cpy;

	cpy = dest;
	while (*cpy != '\0')
		cpy++;
	while (*src != '\0')
	{
		*cpy = *(unsigned char *)src;
		cpy++;
		src++;
	}
	*cpy = '\0';
	return (dest);
}

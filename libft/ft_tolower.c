int	ft_tolower(int c)
{
	int	i;

	i = 0;
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// int	main(void)
// {
// 	unsigned char	c;

// 	c = 'A';
// 	c = ft_lower(c);
// 	printf("%c\n", c);
// }

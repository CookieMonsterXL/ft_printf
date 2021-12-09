int	ft_toupper(int c)
{
	int	i;

	i = 0;
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

// int	main(void)
// {
// 	unsigned char	c;

// 	c = 'a';
// 	c = ft_toupper(c);
// 	printf("%c\n", c);
// }

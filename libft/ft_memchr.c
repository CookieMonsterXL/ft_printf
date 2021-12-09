#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (n > i)
	{
		if (ptr[i] == (unsigned char)c)
			return (ptr + i);
		i++;
	}
	return (NULL);
}

// int 	main(void)
// {
// 	char string[20] = {0, 1, 2 ,3 ,4 ,5};
// 	char *pnt;
// 	int j;

// 	j = (2 + 256);
// 	pnt = ft_memchr(string, 0, 5);
// 	printf("%s\n", pnt);
// 	write(1, j, 1);
// }

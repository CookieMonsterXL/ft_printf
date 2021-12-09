#include <stdlib.h>

void	*ft_memset(void *str, int c, unsigned int len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}

// int	main(void)
// {
// 	char	zin[] = "test mijn appels";

// 	ft_memset(zin, 'b', 3);
// 	printf("%s\n", zin);
// 	return (0);
// }

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!n || dest == src)
		return (dest);
	while (n > i)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char src[] = "deze appels";
// 	char dest[] = "Die peren";
// 	char *test;

// 	test = ft_memcpy(dest, src, 4);
// 	printf("%s\n", dest);
// 	printf("%s\n", src);
// }

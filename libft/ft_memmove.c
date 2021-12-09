#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	if (src > dest)
	{
		while (i < len)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			((char *)dest)[len - 1] = ((char *)src)[len - 1];
			len--;
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char src[] = "appels";
// 	char dest[] = "Koeien";
// 	char *test;

// 	test = ft_memmove(dest, src, 10);
// 	printf("Dest =%s\n", dest);
// 	printf("Src  =%s\n", src);
// }

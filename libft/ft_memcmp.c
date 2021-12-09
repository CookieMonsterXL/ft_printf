#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (n > i)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	char string1 [20] = {-128, 0, 127, 0};
// 	char string2 [20] = {0, 0, 127, 0};
// 	int check;

// 	check = ft_memcmp(string2, string1, 6);
// 	printf("%d\n", check);
// }

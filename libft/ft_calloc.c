#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

// int main(void)
// {
// char *ptr;

// ptr = ft_calloc(5, sizeof(char));
// printf("%s\n", ptr);
// }

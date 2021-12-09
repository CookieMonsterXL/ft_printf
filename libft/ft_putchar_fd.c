#include "libft.h"
#include <unistd.h>

int	ft_putchar_fd(char c, int fd)
{
	int	count;

	count = write(fd, &c, 1);
	return (count);
}

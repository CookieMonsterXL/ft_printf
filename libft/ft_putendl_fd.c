#include "libft.h"
#include <unistd.h>

int	ft_putendl_fd(char *s, int fd)
{
	int	i;
	int	count;

	if (!s)
		return (0);
	i = ft_strlen(s);
	count = write(fd, (s), i);
	count += write(fd, "\n", 1);
	return (count);
}

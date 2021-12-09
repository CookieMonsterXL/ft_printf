#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)s;
	i = ft_strlen(s);
	if ((char)c == '\0')
		return (ptr + i);
	i--;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (ptr + i);
		i--;
	}
	return (0);
}

// int	main(void)
// {
// 	char			str[10] = "Tiemen";
// 	unsigned char	c = '\0';
// 	char			*pnt;
//
// 	pnt = ft_strrchr(str, c);
// 	printf("%c\n", *pnt);
// }

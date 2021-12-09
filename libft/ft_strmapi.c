#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		s_len;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	ptr = malloc((s_len + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

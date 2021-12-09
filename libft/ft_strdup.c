#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len_s1;

	len_s1 = ft_strlen(s1);
	ptr = malloc((len_s1 + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[len_s1] = '\0';
	while (len_s1 >= 0)
	{
		len_s1--;
		ptr[len_s1] = s1[len_s1];
	}
	return (ptr);
}

// int main(void)
// {
// 	char	string1[] = "coucou";
// 	char	*cpy;
// 	char	*cpy2;
//
// 	cpy = ft_strdup(string1);
// 	printf("%s$\n", cpy);
// 	printf("string len: %lu\n", strlen(cpy));
// 	cpy2 = ft_strdup(string1);
// 	printf("%s$\n", cpy2);
// 	printf("string len: %lu\n", strlen(cpy2));
// }

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	minplus;

	i = 0;
	num = 0;
	minplus = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minplus = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num *= 10;
		num += str[i] - 48;
		i++;
	}
	return (num * minplus);
}

// int main(void)
// {
// 	char string1[20] = "123479345";
// 	char string2[20] = "tiemen1";
// 	int num1;
// 	int num2;

// 	num1 = ft_atoi(string1);
// 	num2 = ft_atoi(string2);
// 	printf("num1= %d\n", num1);
// 	printf("num2= %d\n", num2);

// }

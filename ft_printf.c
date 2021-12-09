//
// Created by Tiemen Bouma on 11/19/21.
//
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	func(const char *str, va_list argList)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
			count += write(1, str + i, 1);
		if (str[i] == '%' && str[i + 1] && str[i + 1] != '\a'
			&& str[i + 1] != '\b' && str[i + 1] != '\f' && str[i + 1] != '\n'
			&& str[i + 1] != '\r' && str[i + 1] != '\t' && str[i + 1] != '\v')
		{
			i++;
			count += print(str, argList, i);
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	argList;
	int		count;

	count = 0;
	va_start(argList, str);
	count += func(str, argList);
	va_end(argList);
	return (count);
}
//int main(void)
//{
//	char			a;
//	char			*str = "abcdefg";
//	char			*p;
//	int				i;
//	unsigned int	u;
//	unsigned int	hex;
//	unsigned int	hex2;
//
//	i = 1;
//	p = &a;
//	a = 'b';
//	u = 2;
//	hex = 233451523;
//	hex2 = -0xDEA3003;
//	ft_printf("alleen tekst");
//	printf("\n");
//	ft_printf("Print char b: %c en int i: %i", a, i);
//	printf("\n");
//	ft_printf("Print string str: %s", str);
//	printf("\n");
//	ft_printf("ft_Printf pointer adres p: %p", p);
//	printf("\n");
//	printf("Printf pointer adres p: %p", p);
//	printf("\n");
//	ft_printf("Print int i: %d", i);
//	printf("\n");
//	ft_printf("Print unsigned int u: %u", u);
//	printf("\n");
//	ft_printf("ft_Print hexadec unsigned hexup: %X", hex);
//	printf("\n");
//	printf("Print hexadec unsigned hexup: %X", hex);
//	printf("\n");
//	ft_printf("ft_Print hexadec unsigned hexlo: %x", hex);
//	printf("\n");
//	printf("Printf hexadec unsigned hexlo: %x", hex);
//	printf("\n");
//	ft_printf("Print percentage: %%");
//	printf("\n");
//	ft_printf("ft_Print hexadec minus hexlo2: %x", hex2);
//	printf("\n");
//	printf("Printf hexadec minus unsigned hexlo2: %x", hex2);
//	printf("\n");
//	return (0);
//}
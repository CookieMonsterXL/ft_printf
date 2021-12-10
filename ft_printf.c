//
// Created by Tiemen Bouma on 11/19/21.
//
#include "headers/printf_helper.h"
#include <stdarg.h>
#include <unistd.h>

static int check_flag(char c)
{
	return (c == 'u' || c == 'x' || c == 'X' || c == 'd' || c == 'i' || c == 'p' || c == 'c' || c == 's' || c == '%');
}

int	print(const char *str, va_list argList)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
			count += write(1, str + i, 1);
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if(!check_flag(str[i]))
				return (count += write(1, "|No valid flag after %. Stopped|", 24));
			count += print_flag(str, argList, i);
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
	count += print(str, argList);
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
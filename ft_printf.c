//
// Created by Tiemen Bouma on 11/19/21.
//
#include "libs/ft_printf.h"
#include "libs/libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

#include <stdint.h>

int ft_printf	(const char *str, ...)
{
	va_list argList;
	char *ptr;
	char **str_arr;
	int i;
	int j;

	i = 0;
	va_start(argList, str);
//	if (str[i] != '%')
//		write(1, str, 1);
//	else if (str[i] == '%')
	while (str[i])
	{
		if (str[i] != '%' && str[i - 1] != '%')
			write(1, str + i, 1);
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				ft_putchar_fd(va_arg(argList, int), 1);
			if (str[i] == 's')
				ft_putstr_fd(va_arg(argList, char *), 1);
			if (str[i] == 'p')
				ft_putstr_fd(ft_xtoa((long long)va_arg(argList, void *)), 1);
			if (str[i] == 'd' || str[i] == 'i')
				ft_putnbr_fd(va_arg(argList, int), 1);
			if (str[i] == 'u')
				ft_putnbr_fd(va_arg(argList, unsigned int), 1);
			if (str[i] == 'x')
			{
				j = 0;
				ptr = ft_xtoa(va_arg(argList, unsigned int));
				while (ptr[j]) {
					ptr[j] = ft_tolower(ptr[j]);
					j++;
				}
				ft_putstr_fd((char *)ptr, 1);
			}
			if (str[i] == 'X')
				ft_putstr_fd(ft_xtoa(va_arg(argList, unsigned int)), 1);
			if (str[i] == '%')
				ft_putchar_fd('%', 1);
		}
		i++;
	}
	va_end(argList);
	return (0);
}
int main(void)
{
	char			a;
	char			*str = "abcdefg";
	char			*p;
	int				i;
	unsigned int	u;
	unsigned int	hex;
	unsigned int	hex2;

	i = 1;
	p = &a;
	a = 'b';
	u = 2;
	hex = 233451523;
	hex2 = -0xDEA3003;
	ft_printf("alleen tekst");
	printf("\n");
	ft_printf("Print char b: %c en int i: %i", a, i);
	printf("\n");
	ft_printf("Print string str: %s", str);
	printf("\n");
	ft_printf("ft_Printf pointer adres p: %p", p);
	printf("\n");
	printf("Printf pointer adres p: %p", p);
	printf("\n");
	ft_printf("Print int i: %d", i);
	printf("\n");
	ft_printf("Print unsigned int u: %u", i);
	printf("\n");
	ft_printf("ft_Print hexadec unsigned hexup: %X", hex);
	printf("\n");
	printf("Print hexadec unsigned hexup: %X", hex);
	printf("\n");
	ft_printf("ft_Print hexadec unsigned hexlo: %x", hex);
	printf("\n");
	printf("Printf hexadec unsigned hexlo: %x", hex);
	printf("\n");
	ft_printf("Print percentage: %%");
	printf("\n");
	ft_printf("ft_Print hexadec unsigned hexlo2: %x", hex2);
	printf("\n");
	printf("Printf hexadec unsigned hexlo2: %x", hex2);
	printf("\n");
	return (0);
}
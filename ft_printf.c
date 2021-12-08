//
// Created by Tiemen Bouma on 11/19/21.
//
#include "libs/ft_printf.h"
#include "libs/libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

int	xup_print(va_list argList)
{
	char *ptr;
	int count;

	count = 0;
	ptr = ft_ull_base(va_arg(argList, long long), 16);
	count += ft_putstr_fd(ptr, 1);
	free(ptr);
	return (count);
}

int x_print(va_list argList)
{
	int j;
	char *ptr;
	int count;

	count = 0;
	j = 0;
	ptr = ft_ull_base(va_arg(argList, long long), 16);
	while (ptr[j]) {
		ptr[j] = ft_tolower(ptr[j]);
		j++;
	}
	count += ft_putstr_fd((char *)ptr, 1);
	free(ptr);
	return (count);
}

int p_print(va_list argList)
{
	int j;
	int count;
	char *ptr;

	count = 0;
	j = 0;
	ptr = ft_ull_base(va_arg(argList, unsigned long long), 16);
	while (ptr[j])
	{
		ptr[j] = ft_tolower(ptr[j]);
		j++;
	}
	count += ft_putstr_fd("0x",1);
	count += ft_putstr_fd((char *)ptr, 1);
	free(ptr);
	return (count);
}

int s_print(va_list argList)
{
	char *ptr;
	int count;

	count = 0;
	ptr = va_arg(argList, char *);
	if (ptr == NULL)
		count += ft_putstr_fd("(null)", 1);
	else
		count += ft_putstr_fd(ptr, 1);
	return (count);
}

int	print(const char *str, va_list argList, int i)
{
	int count;

	count = 0;
	if (str[i] == 'c')//DONE!
		count += ft_putchar_fd(va_arg(argList, int), 1);
	if (str[i] == 's') //DONE!
		count += s_print(argList);
	if (str[i] == 'p') //DONE!
		count += p_print(argList);
	if (str[i] == 'd' || str[i] == 'i')//DONE!
		count += ft_putnbr_fd(va_arg(argList, int), 1);
	if (str[i] == 'u')//DONE!
		count += ft_putnbr_fd(va_arg(argList, unsigned int), 1);
	if (str[i] == 'x')//DONE!
		count += x_print(argList);
	if (str[i] == 'X')//DONE!
		count += xup_print(argList);
	if (str[i] == '%')//DONE!
		count += ft_putchar_fd('%', 1);
	return (count);
}

int func(const char *str, va_list argList)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
			count += write(1, str + i, 1);
		if (str[i] == '%')
		{
			i++;
			count += print(str, argList, i);
		}
		i++;
	}
	return (count);
}

int ft_printf	(const char *str, ...)
{
	va_list argList;
	int count;

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
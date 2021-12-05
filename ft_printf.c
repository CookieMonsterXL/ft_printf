//
// Created by Tiemen Bouma on 11/19/21.
//
#include "libs/ft_printf.h"
#include "libs/libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

#include <stdint.h>

int ft_printf	(const char *str, ...) {
	va_list argList;
	void *ptr;
	char **str_arr;
	int i;
	int j;

	i = 0;
	j = 0;
	va_start(argList, str);
//	if (str[i] != '%')
//		write(1, str, 1);
//	else if (str[i] == '%')
	while (str[i]) {
		if (str[i] != '%' && str[i - 1] != '%')
			write(1, str + i, 1);
		if (str[i] == '%') {
			i++;
			if (str[i] == 'c') {
				ptr = va_arg(argList, char);
				ft_putchar_fd(*(char *) ptr, 1);
			}
			if (str[i] == 's') {
				ptr = va_arg(argList, char *);
				ft_putstr_fd(ptr, 1);
			}
			if (str[i] == 'p') {
				ptr = va_arg(argList, int *);
				ptr = ft_xtoa(*(int *) ptr);
				ft_putstr_fd(ptr, 1);
			}
			if (str[i] == 'd' || str[i] == 'i') {
				ptr = va_arg(argList, int);
				ft_putnbr_fd(*(int *) ptr, 1);
			}
			if (str[i] == 'u') {
				ptr = va_arg(argList, unsigned int);
				ft_putnbr_fd(*(unsigned int *) ptr, 1);
			}
			if (str[i] == 'x')
			{
				ptr = va_arg(argList, unsigned int);
				ptr = ft_xtoa(*(unsigned int *) ptr);
				while (ptr[j]) {
					ptr[j] = ft_tolower((int *)ptr[j]);
					j++;
				}
				ft_putstr_fd(ptr, 1)
			}
			if (str[i] == 'X') {
				ptr = va_arg(argList, unsigned int);
				ft_xtoa(*(unsigned int *) ptr);
				ft_putstr_fd(ptr, 1);
			}
			if (str[i] == '%') {
				ptr = va_arg(argList, char);
				ft_putchar_fd(*(char *) ptr, 1);
			}
			i++;
			j = 0;
		}
	}
}

int main(void)
{
	int a;

	a = 1;
	ft_printf("test");
	printf("\n");
	ft_printf("%d", a);
	printf("\n");
}


	/*
	str_arr = ft_split(str, '%');
	while (str_arr[i][0] != NULL)
		i++;
	while (i < j)
	{
		if (str_arr[j][0] == 'c')
		{
			ptr = va_arg(argList, char);
			ft_putchar_fd((char *)ptr, 1);
		}
		if (str_arr[j][0] == 's')
		{
			ptr = va_arg(argList, (char *));
			ft_putstr_fd(ptr, 1)
		}
		if (str_arr[j][0] == 'p')
			ptr = va_arg(argList, (void *));
		if (str_arr[j][0] == 'd')
			ptr = va_arg(argList, int);
		if (str_arr[j][0] == 'i')
			ptr = va_arg(argList, int);
		if (str_arr[j][0] == 'u')
			ptr = va_arg(argList, unsigned int);
		if (str_arr[j][0] == 'x')
			ptr = va_arg(argList, unsigned int);
		if (str_arr[j][0] == 'X')
			ptr = va_arg(argList, unsigned int);
		if (str_arr[j][0] == '%')
			ptr = va_arg(argList, char);
		j++;
	}
	*/

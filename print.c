//
// Created by Tiemen Bouma on 12/8/21.
//
#include <stdarg.h>
#include "libs/libft/libft.h"

int	xup_print(va_list argList)
{
	char	*ptr;
	int		count;

	count = 0;
	ptr = ft_ull_base(va_arg(argList, long long), 16);
	count += ft_putstr_fd(ptr, 1);
	free(ptr);
	return (count);
}

int	x_print(va_list argList)
{
	int		j;
	char	*ptr;
	int		count;

	count = 0;
	j = 0;
	ptr = ft_ull_base(va_arg(argList, long long), 16);
	while (ptr[j])
	{
		ptr[j] = ft_tolower(ptr[j]);
		j++;
	}
	count += ft_putstr_fd((char *)ptr, 1);
	free(ptr);
	return (count);
}

int	p_print(va_list argList)
{
	int		j;
	int		count;
	char	*ptr;

	count = 0;
	j = 0;
	ptr = ft_ull_base(va_arg(argList, unsigned long long), 16);
	while (ptr[j])
	{
		ptr[j] = ft_tolower(ptr[j]);
		j++;
	}
	count += ft_putstr_fd("0x", 1);
	count += ft_putstr_fd((char *)ptr, 1);
	free(ptr);
	return (count);
}

int	s_print(va_list argList)
{
	char	*ptr;
	int		count;

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
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_putchar_fd(va_arg(argList, int), 1);
	if (str[i] == 's')
		count += s_print(argList);
	if (str[i] == 'p')
		count += p_print(argList);
	if (str[i] == 'd' || str[i] == 'i')
		count += ft_putnbr_fd(va_arg(argList, int), 1);
	if (str[i] == 'u')
		count += ft_putnbr_fd(va_arg(argList, unsigned int), 1);
	if (str[i] == 'x')
		count += x_print(argList);
	if (str[i] == 'X')
		count += xup_print(argList);
	if (str[i] == '%')
		count += ft_putchar_fd('%', 1);
	return (count);
}

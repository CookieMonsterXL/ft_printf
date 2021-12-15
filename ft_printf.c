/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:45:41 by tbouma            #+#    #+#             */
/*   Updated: 2021/12/15 13:13:56 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "headers/printf_helper.h"

static int	check_flag(char c)
{
	return (c == 'u' || c == 'x' || c == 'X' || c == 'd'
		|| c == 'i' || c == 'p' || c == 'c' || c == 's' || c == '%');
}

int	print(const char *str, va_list *argList)
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
			if (!check_flag(str[i]))
				return (-1);
			count += print_flag(str, argList, i);
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arglist;
	int		count;

	count = 0;
	va_start(arglist, str);
	count += print(str, &arglist);
	va_end(arglist);
	return (count);
}

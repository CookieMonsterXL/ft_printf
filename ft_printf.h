//
// Created by Tiemen Bouma on 11/19/21.
//

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);

int	xup_print(va_list argList);

int	x_print(va_list argList);

int	p_print(va_list argList);

int	s_print(va_list argList);

int	print(const char *str, va_list argList, int i);

#endif

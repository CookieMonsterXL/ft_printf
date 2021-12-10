//
// Created by Tiemen Bouma on 11/19/21.
//

#ifndef PRINTF_HELPER_H
# define PRINTF_HELPER_H
# include <stdarg.h>
# include <stdio.h>

int	xup_print(va_list *argList);

int	x_print(va_list *argList);

int	p_print(va_list *argList);

int	s_print(va_list *argList);

int	print_flag(const char *str, va_list *argList, int i);

#endif

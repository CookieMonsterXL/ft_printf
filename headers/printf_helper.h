/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_helper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:32:20 by tbouma            #+#    #+#             */
/*   Updated: 2021/12/15 13:18:52 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_HELPER_H
# define PRINTF_HELPER_H
# include <stdarg.h>
# include <stdio.h>

int	print_flag(const char *str, va_list *argList, int i);

#endif

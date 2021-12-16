/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_helper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:32:20 by tbouma            #+#    #+#             */
/*   Updated: 2021/12/16 13:55:50 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_HELPER_H
# define PRINTF_HELPER_H
# include <stdarg.h>

int	print_flag(const char *str, va_list *argList, int i);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 23:09:17 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/22 23:15:38 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_FUNCTS_H
#define PRINT_FUNCTS_H

#include <stdarg.h>
#include <stdlib.h>

size_t	print_char(char *substr, size_t num_print, va_list ap);
size_t	print_str(char *substr, size_t num_print, va_list ap);
size_t	print_ptr(char *substr, size_t num_print, va_list ap);
size_t	print_sign_dec(char *substr, size_t num_print, va_list ap);
size_t	print_sign_int(char *substr, size_t num_print, va_list ap);
size_t	print_unsi_dec(char *substr, size_t num_print, va_list ap);
size_t	print_hex_low(char *substr, size_t num_print, va_list ap);
size_t	print_hex_upp(char *substr, size_t num_print, va_list ap);

#endif

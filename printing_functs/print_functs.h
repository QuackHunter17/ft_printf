/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 23:09:17 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/26 14:48:15 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_FUNCTS_H
#define PRINT_FUNCTS_H

#include <stdarg.h>
#include <stdlib.h>
#include "../libft/libft.h"

char		*apply_prec(char *s, int precision);
char		*apply_padd(char *s, int is_rev, int pad_with_zero, int width);
char		*apply_sign(char *s, int plus_flag, int space_flag, int is_neg);
int	*check_flags(char *s);
size_t	determine_size(unsigned int num);
char	*altern_format(char *s, int is_alt);
char	*num_to_hex(unsigned int num, char *base_16);
char	*populate_hex_arr(int is_upp);
size_t	print_char(char *substr, size_t num_print, va_list *ap);
size_t	print_str(char *substr, size_t num_print, va_list *ap);
size_t	print_ptr(char *substr, size_t num_print, va_list *ap);
size_t	print_sign_dec(char *substr, size_t num_print, va_list *ap);
size_t	print_unsi_dec(char *substr, size_t num_print, va_list *ap);
size_t	print_hex_low(char *substr, size_t num_print, va_list *ap);
size_t	print_hex_upp(char *substr, size_t num_print, va_list *ap);

#endif

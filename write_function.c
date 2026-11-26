/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:42:03 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/25 17:48:06 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	write_function(char *substr, size_t num_print, va_list *ap)
{
	char	conv_char;

	conv_char = substr[ft_strlen(substr) - 1];
	if (conv_char == 'c')
		num_print = print_char(substr, num_print, ap);
	else if (conv_char == 's')
		num_print = print_str(substr, num_print, ap);
	else if (conv_char == 'p')
		num_print = print_ptr(substr, num_print, ap);
	else if (conv_char == 'd' || conv_char == 'i')
		num_print = print_sign_dec(substr, num_print, ap);
	else if (conv_char == 'u')
		num_print = print_unsi_dec(substr, num_print, ap);
	else if (conv_char == 'x')
		num_print = print_hex_low(substr, num_print, ap);
	else if (conv_char == 'X')
		num_print = print_hex_upp(substr, num_print, ap);
	return (num_print);
}

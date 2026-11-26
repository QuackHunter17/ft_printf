/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_low.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 20:57:40 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/26 14:51:21 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functs.h"

//flags[] = {-, 0, #, +, (space), width, .};

size_t	print_hex_low(char *substr, size_t num_print, va_list *ap)
{
	char	*hex_str;
	unsigned int	num_rep_of_hex;
	int	*flags;
	size_t	hex_len;
	char	*base_16;

	base_16 = populate_hex_arr(0);
	flags = check_flags(substr);
	num_rep_of_hex = va_arg(*ap, unsigned int);
	hex_str = num_to_hex(num_rep_of_hex, base_16);	
	hex_str = apply_prec(hex_str, flags[6]);
	hex_str = apply_sign(hex_str, flags[3], flags[4], 0);
	hex_str = apply_sign(hex_str, flags[0], flags[1], flags[5]);
	hex_str = altern_format(hex_str, flags[2]);
	ft_putstr_fd(hex_str, 1);
	hex_len = ft_strlen(hex_str);
	free(hex_str);
	free(flags);
	free(base_16);
	return (num_print + hex_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsi_dec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:15:55 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/26 14:52:53 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functs.h"

//flags[] = {-, 0, #, +, (space), width, .};
size_t	print_unsi_dec(char *substr, size_t num_print, va_list *ap)
{
	int	*flags;
	unsigned int	u;
	char	*u_str;
	size_t	u_len;

	flags = check_flags(substr);
	u = va_arg(*ap, unsigned int);
	u_str = ft_itoa(u);
	u_str = apply_prec(u_str, flags[6]);
	u_str = apply_sign(u_str, flags[3], flags[4], 0);
	u_str = apply_padd(u_str, flags[0], flags[1], flags[5]);
	ft_putstr_fd(u_str, 1);
	u_len = ft_strlen(u_str);
	free(u_str);
	free(flags);
	return (num_print + u_len);
}

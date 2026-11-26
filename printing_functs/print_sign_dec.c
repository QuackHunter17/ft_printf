/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sign_dec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:15:55 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/26 14:52:25 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functs.h"

//flags[] = {-, 0, #, +, (space), width, .};
size_t	print_sign_dec(char *substr, size_t num_print, va_list *ap)
{
	int		*flags;
	int		d;
	char	*d_str;
	size_t	d_len;
	int	is_neg;

	flags = check_flags(substr);
	d = va_arg(*ap, int);
	if (d < 0)
	{
		d *= -1;
		is_neg = 1;
	}
	else
		is_neg = 0;
	d_str = ft_itoa(d);
	d_str = apply_prec(d_str, flags[6]);
	d_str = apply_sign(d_str, flags[3], flags[4], is_neg);
	d_str = apply_padd(d_str, flags[0], flags[1], flags[5]);
	ft_putstr_fd(d_str, 1);
	d_len = ft_strlen(d_str);
	free(d_str);
	free(flags);
	return (num_print + d_len);
}

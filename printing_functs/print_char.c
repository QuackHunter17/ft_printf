/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 23:02:12 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/25 17:52:11 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functs.h"

/*
The flags variable will be like this:
flags[] = {-, 0, #, +, (space), width, .};
each of the flags except the width and precision will contain one of the
following values:
• 1: it means the flag is present
• 0: it means the flag is absent
the width and precision cells will contain an integer number.
if no number provided, it will be 0.
*/
size_t	print_char(char *substr, size_t num_print, va_list *ap)
{
	int	*flags;
	char	*final_str;
	char	c;
	size_t	len;

	flags = check_flags(substr);
	c = va_arg(*ap, int) + '0';
	final_str = apply_padd(&c, flags[0], flags[1], flags[5]);
	ft_putstr_fd(final_str, 1);
	len = ft_strlen(final_str);
	free(final_str);
	free(flags);
	return (num_print + len);
}

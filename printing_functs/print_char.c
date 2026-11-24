/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 23:02:12 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/23 12:31:55 by mousaidi         ###   ########.fr       */
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
	char	pad_char;
	char	c;
	int	i;
	
	flags = check_flags(substr);
	c = va_arg(*ap, int) + '0';
	pad_char = ' ';
	print_with_padd(c, flags[0], pad_char, flags[5]);
	return (num_print + (size_t)width);
}

static void	print_with_padd(char c, int rev, char padd_char, int len)
{
	int	i;

	i = 0;
	if (rev)
		write(1, &c, 1);
	while (i < len - 1)
	{
		write(1, padd_char, 1);
		i++;
	}
	if (!rev)
		write(1, &c, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 08:21:18 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/26 14:52:44 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functs.h"

static size_t	print_with_padd(char *s, char pad_char, int *flags);

size_t	print_str(char *substr, size_t num_print, va_list *ap)
{
	int	*flags;
	char	pad_char;
	char	*s;

	flags = check_flags(substr);
	s = va_arg(*ap, char *);
	pad_char = ' ';
	num_print += print_with_padd(s, pad_char, flags);
	free(flags);
	return (num_print);
}

static size_t	print_with_padd(char *s, char pad_char, int *flags)
{
	size_t	i;
	size_t	j;
	char	*s_after_prec;
	size_t	s_after_prec_len;

	i = 0;
	s_after_prec = malloc(sizeof(char) * (flags[6] + 1));
	if (!s_after_prec)
		return (0);
	while (s[i] != '\0' && i < (size_t)flags[6])
	{
		s_after_prec[i] = s[i];
		i++;
	}
	if ((size_t)flags[5] > i)
		i = 0;
	else
		i = flags[5] - i;
	j = 0;
	if (flags[0])
		ft_putstr_fd(s_after_prec, 1);
	while (j < i)
	{
		ft_putchar_fd(pad_char, 1);
		j++;
	}
	if (!flags[0])
		ft_putstr_fd(s_after_prec, 1);
	s_after_prec_len = ft_strlen(s_after_prec);
	free(s_after_prec);
	return (j + s_after_prec_len);
}

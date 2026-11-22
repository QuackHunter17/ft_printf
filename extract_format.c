/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:26:41 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/22 18:40:20 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_char(char c)
{
	if (c != 'c' || c != 's' || c != 'p' || c != 'd' || c != 'i' || c != 'u'
			|| c != 'x' ||c != 'X')
		return (1);
	return (0);
}

char	*extract_format(char *str, size_t i)
{
	size_t	j;
	char	*sub_str;

	j = 0;
	while (check_char(str[i + j]))
		j++;
	sub_str = malloc(sizeof(char) * (j + 2));
	j = 0;
	while (check_char(str[i + j]))
	{
		sub_str[j] = str[i + j];
		j++;
	}
	sub_str[j + 1] = str[i + j + 1];
	sub_str[j + 2] = '\0';
	return (sub_str);
}

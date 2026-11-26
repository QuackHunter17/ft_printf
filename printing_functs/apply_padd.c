/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_padd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:15:55 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/26 14:39:45 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functs.h"

//flags[] = {-, 0, #, +, (space), width, .};

char	*apply_padd(char *s, int is_rev, int pad_with_zero, int width)
{
	size_t	i;
	size_t	s_len;
	char	*ret_str;
	size_t	j;

	i = 0;
	j = 0;
	if (is_rev && pad_with_zero)
		pad_with_zero = 0;
	s_len = ft_strlen(s);
	if (s_len >= (size_t)width)
		return (s);
	ret_str = malloc(sizeof(char) * (width + 1));
	if (!ret_str)
	{
		free (s);
		return (NULL);
	}
	while (i < s_len && is_rev)
	{
		ret_str[i] = s[i];
		i++;
	}
	while (i + j < (size_t)width)
	{
		if (pad_with_zero)
			ret_str[i + j] = '0';
		else
			ret_str[i + j] = ' ';
		j++;
	}
	while (!is_rev && i < s_len)
	{
		ret_str[i + j] = s[i];
		i++;
	}
	free(s);
	return (ret_str);
}

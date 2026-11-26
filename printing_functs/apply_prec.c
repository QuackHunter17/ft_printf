/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:15:55 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/26 14:40:40 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functs.h"

//flags[] = {-, 0, #, +, (space), width, .};

char	*apply_prec(char *s, int precision)
{
	size_t	i;
	size_t	s_len;
	char	*ret_str;
	size_t	j;

	s_len = ft_strlen(s);
	if (precision == -1)
		return (s);
	if (precision == 0 && s_len == 1 && s[0] == '0')
	{
		free(s);
		ret_str = malloc(sizeof(char) * 1);
		ret_str[0] = '\0';
		return (ret_str);
	}
	if (s_len >= (size_t)precision)
		return (s);
	i = 0;
	j = 0;
	ret_str = malloc(sizeof(char) * (precision + 1));
	if (!ret_str)
	{
		free(s);
		return (NULL);
	}
	while (i < ((size_t)precision) - s_len)
	{
		ret_str[i] = '0';
		i++;
	}
	while (j < s_len)
	{
		ret_str[i + j] = s[j];
		j++;
	}
	free(s);
	ret_str[i + j] = '\0';
	return (ret_str);
}

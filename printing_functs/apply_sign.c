/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:15:55 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/26 14:40:57 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functs.h"

//flags[] = {-, 0, #, +, (space), width, .};

static char	*populate_new_str(char *s1, char *s2, size_t s2_len);

char	*apply_sign(char *s, int plus_flag, int space_flag, int is_neg)
{
	char	*str_with_sign;
	size_t	s_len;

	if (!plus_flag && !space_flag && !is_neg)
		return (s);
	s_len = ft_strlen(s);
	str_with_sign = malloc(sizeof(char) * (s_len + 2));
	if (!str_with_sign)
	{
		free(s);
		return (NULL);
	}
	str_with_sign = populate_new_str(str_with_sign, s, s_len);
	if (is_neg)
		str_with_sign[0] = '-';
	else if (plus_flag)
		str_with_sign[0] = '+';
	else if (space_flag)
		str_with_sign[0] = ' ';
	free(s);
	return (str_with_sign);
}

static char	*populate_new_str(char *s1, char *s2, size_t s2_len)
{
	s1[s2_len + 1] = '\0';
	while (s2_len > 0)
	{
		s2_len--;
		s1[s2_len + 1] = s2[s2_len];
	}
	s1[s2_len + 1] = s2[s2_len];
	return (s1);
}

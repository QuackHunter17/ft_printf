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

static size_t	add_padd_rev(char *s, size_t i, size_t width);
static size_t	add_padd_0(char *s, size_t i, size_t width, size_t s_len);
static size_t add_padd_norm(char *s, size_t i, size_t width, size_t s_len);
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
	if (is_rev)
		i = add_padd_rev(ret_str, i, (size_t)width);
	else if (pad_with_zero)
		i = add_padd_0(ret_str, i, (size_t)width, s_len);
	else
		i = add_padd_norm(ret_str, i, (size_t)width, s_len);
	while (!is_rev && i < (size_t)width)
	{
		ret_str[i] = s[i - (size_t)width + s_len];
		i++;
	}
	ret_str[i] = '\0';
	free(s);
	return (ret_str);
}

static size_t	add_padd_rev(char *s, size_t i, size_t width)
{
	while (i < width)
	{
		s[i] = ' ';
		i++;
	}
	return (i);
}

static size_t	add_padd_0(char *s, size_t i, size_t width, size_t s_len)
{
	while (i < width - s_len)
	{
		s[i] = '0';
		i++;
	}
	return (i);
}

static size_t add_padd_norm(char *s, size_t i, size_t width, size_t s_len)
{
	while (i < width - s_len)
	{
		s[i] = ' ';
		i++;
	}
	return (i);
}

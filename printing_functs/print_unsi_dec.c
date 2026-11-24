/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsi_dec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:15:55 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/24 20:53:45 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functs.h"

//flags[] = {-, 0, #, +, (space), width, .};
size_t print_unsi_dec(char *substr, size_t num_print, va_list *ap)
{
	int	*flags;
	unsigned int	u;

	flags = check_flags(substr);
	u = va_arg(*ap, unsigned int);
	if (flags[0] && flags[1])
		flags[1] = 0;
	if (flags[3] && flags[4])
		flags[4] = 0;
	if (flags[1] && flags[6] > 1)
		flags[1] = 0;
	num_print += print_with_padd(u, flags);
	return (num_print);
}

static size_t	print_with_padd(unsigned int u, int *flags)
{
	char	*u_str;
	size_t	num_of_prin_chars;

	u_str = ft_itoa(u);
	u_str = apply_prec(u_str, flags[6]);
	u_str = apply_sign(u_str, flags[3], fags[4]);
	u_str = padd(u_str, flags[0], flags[1], flags[5]);
	num_of_prin_chars = ft_strlen(u_str);
	return (num_of_prin_chars);
}

static char	*apply_prec(char *s, int precision)
{
	size_t	i;
	size_t	s_len;
	char	*ret_str;
	size_t	j;

	s_len = ft_strlen(s);
	if (precision == 0 && s_len == 1 && s[0] == '0')
	{
		free(s);
		return ("");
	}
	if (s_len >= precision)
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

static char	*apply_sign(char *s, int plus_flag, int space_flag)
{
	size_t	i;
	char	*str_with_sign;
	size_t	s_len;

	if (!plus_flag && !space_flag)
		return (s);
	s_len = ft_strlen(s);
	str_with_sign = malloc(sizeof(char) * (s_len + 1));
	if (!str_with_sign)
	{
		free(s);
		return (NULL);
	}
	while (s_len > 0)
	{
		s_len--;
		str_with_neg_sign[s_len + 1] = s[s_len];
	}
	if (plus_flag)
		str_with_sign[0] = '+';
	else if (space_flag)
		str_with_sign[0] = ' ';
	free(s);
	return (str_with_sign);
}

static char	*padd(char *s, int is_rev, int pad_with_zero, int width)
{
	size_t	i;
	size_t	s_len;
	char	*ret_str;
	size_t	j;

	i = 0;
	j = 0;
	s_len = ft_strlen(s);
	if (s_len >= width)
		return (s);
	ret_str = malloc(sizeof(char) * (width + 1));
	if (!ret_str)
	{
		free(s);
		return (NULL);
	}
	while (i < s_len && is_rev)
	{
		ret_str[i] = s[i];
		i++;
	}
	while (i + j < width)
	{
		if (pad_with_zero)
			ret_str[i + j] = '0';
		else
			ret_str[i + j] = ' ';
		j++;
	}
	while (!is_rev && i < s_len)
	{
		ret_str[i + j] = str[i];
		i++;
	}
	free(s);
	return (ret_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altern_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 20:57:40 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/25 18:26:19 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functs.h"

//flags[] = {-, 0, #, +, (space), width, .};

char	*altern_format(char *s, int is_alt)
{
	char	*alt_form;
	size_t	len;

	if (!is_alt)
		return (s);
	len = ft_strlen(s);
	alt_form = malloc(sizeof(char) * (len + 3));
	if (!alt_form)
	{
		free(s);
		return (NULL);
	}
	alt_form[len + 3] = '\0';
	while (len > 0)
	{
		len--;
		alt_form[2 + len] = s[len];
	}
	alt_form[0] = '0';
	alt_form[1] = 'x';
	free(s);
	return (alt_form);
}

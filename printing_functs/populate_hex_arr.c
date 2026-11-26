/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_hex_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 18:07:57 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/26 14:46:10 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functs.h"

static char	add_num_rep(int i, int is_upp)
{
	char	c;

	if (i == 10)
		c = 'A';
	if (i == 11)
		c = 'B';
	if (i == 12)
		c = 'C';
	if (i == 13)
		c = 'D';
	if (i == 14)
		c = 'E';
	if (i == 15)
		c = 'F';
	if (is_upp)
		return (c);
	return (c + 32);
}

char	*populate_hex_arr(int is_upp)
{
	size_t	i;
	char	*base_16;

	base_16 = malloc(sizeof(char) * 17);
	if (!base_16)
		return (NULL);
	i = 0;
	while (i < 10)
	{
		base_16[i] = i - '0';
		i++;
	}
	while (i < 17)
	{
		base_16[i] = add_num_rep(i, is_upp);
		i++;
	}
	return (base_16);
}

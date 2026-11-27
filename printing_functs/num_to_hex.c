/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 20:57:40 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/26 14:48:48 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functs.h"

//flags[] = {-, 0, #, +, (space), width, .};
char	*num_to_hex(unsigned int num, char *base_16)
{
	size_t	i;
	size_t	size;
	char	*ret_str;

	size = determine_size(num);
	ret_str = malloc(sizeof(char) * (size + 1));
	if (!ret_str)
		return (NULL);
	i = size;
	while (i > 0)
	{
		i--;
		ret_str[i] = base_16[num % 16];
		num /= 16;
	}
	ret_str[size] = '\0';
	return (ret_str);
}

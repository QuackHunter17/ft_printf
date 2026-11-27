/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 20:57:40 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/26 14:42:19 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functs.h"

//flags[] = {-, 0, #, +, (space), width, .};

size_t	determine_size(unsigned int num)
{
	size_t	size;

	size = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		size++;
	}
	return (size);
}

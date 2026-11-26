/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 14:05:40 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/25 17:55:34 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

//flags = {-, 0, #, +, (space), width, .};
int	main(int argc, char **argv)
{
	int	i;
	(void)argc;
	(void)argv;
/*	printf("Output of ft_printf:\n");
	i = ft_printf("Hello");
	ft_printf("\ni: %d", i);
	printf("--------------");
	printf("Output of printf:\n");
	printf("Hello");
	printf("\ni: %d", i);
	return (0);
*/
	char	*s;
	int	*flags;
	
	s = malloc(sizeof(char) * 3);
	s[0] = '4';
	s[1] = '2';
	s[2] = '\0';
	s = apply_sign(s, 1, 1, 0);
	printf("\"%s\"", s);
	free(s);
	return (0);

}

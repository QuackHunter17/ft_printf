/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 14:05:40 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/22 18:41:46 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	size_t	i;
	char	*substr;
	va_list	ap;
	size_t	j;

	i = 0;
	va_start(ap, str);
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			write(1, '%', 1);
			i += 2;
		}
		else if (str[i] == '%')
		{
			substr = extract_format(str, i);
			j = write_function(substr, j, &ap);
			i += ft_strlen(substr);
		}
		else
		{
			write(1, str[i], 1);
			i++;
		}
		j++;
	}
	return (j);
}

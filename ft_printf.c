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

int	ft_printf(const char *str, ...)
{
	size_t	i;
	char	*substr;
	va_list	ap;
	size_t	num_prin;

	i = 0;
	va_start(ap, str);
	num_prin = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar_fd('%', 1);
			i += 2;
		}
		else if (str[i] == '%')
		{
			substr = extract_format(str, i);
			num_prin = write_function(substr, num_prin, &ap);
			i += ft_strlen(substr);
			free(substr);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
		num_prin++;
	}
	return (num_prin);
}

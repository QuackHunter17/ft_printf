/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 09:57:19 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/23 14:15:21 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functs.h"

size_t	print_ptr(char *substr, cize_t num_print, va_list ap)
{
	int	*flags;
	char	pad_char;
	void	*ptr;
	int	i;

	flags = check_flags(substr);
	ptr = va_arg(*ap, void *);
	pad_char = ' ';
	num_print += print_with_padd(ptr, flags[0], pad_char, flags[5]);
	return (num_print);
}

static size_t	print_with_padd(void *ptr, int rev, char padd_char, int len)
{
	size_t	i;
	char	*ptr_str;
	size_t	str_len;

	i = 0;
	ptr_str = ptr_to_str(ptr);
	ft_putstr("0x");
	if (rev)
	{
		ft_putstr(ptr_str);
	}
	str_len = ft_strlen(ptr_str);
	while (str_len + i < len)
	{
		write(1, padd_char, 1);
		i++;
	}
	if (!rev)
		ft_putstr(ptr_str);
	free(ptr_str);
	return (str_len + i + 2);
}

static char	*ptr_to_str(void *ptr)
{
	unsigned long	num;
	char	base_16[17];
	char	buffer[32];
	int	i;

	num = (unsigned long)ptr;
	i = 0;
	base_16 = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b'
		'c', 'd', 'e', 'f'};
	while (num > 0)
	{
		buffer[i] = base_16[num % 16];
		num /= 16;
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

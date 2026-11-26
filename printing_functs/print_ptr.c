/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 09:57:19 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/26 15:02:22 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functs.h"

static size_t	print_with_padd(void *ptr, int rev, char padd_char, int len);
static char	*ptr_to_str(void *ptr);

size_t	print_ptr(char *substr, size_t num_print, va_list *ap)
{
	int	*flags;
	char	pad_char;
	void	*ptr;

	flags = check_flags(substr);
	ptr = va_arg(*ap, void *);
	pad_char = ' ';
	num_print += print_with_padd(ptr, flags[0], pad_char, flags[5]);
	free(flags);
	return (num_print);
}

static size_t	print_with_padd(void *ptr, int rev, char padd_char, int len)
{
	size_t	i;
	char	*ptr_str;
	size_t	str_len;

	i = 0;
	ptr_str = ptr_to_str(ptr);
	ft_putstr_fd("0x", 1);
	if (rev)
	{
		ft_putstr_fd(ptr_str, 1);
	}
	str_len = ft_strlen(ptr_str);
	while (str_len + i < (size_t)len)
	{
		ft_putchar_fd(padd_char, 1);
		i++;
	}
	if (!rev)
		ft_putstr_fd(ptr_str, 1);
	free(ptr_str);
	return (str_len + i + 2);
}

static char	*ptr_to_str(void *ptr)
{
	size_t	num;
	char	*base_16;
	char	*buffer;
	int	i;

	num = (size_t)ptr;
	i = 0;
	buffer = malloc(sizeof(char) * 32);
	if (!buffer)
		return (NULL);
	base_16 = populate_hex_arr(0);
	while (num > 0)
	{
		buffer[i] = base_16[num % 16];
		num /= 16;
		i++;
	}
	buffer[i] = '\0';
	free(base_16);
	return (buffer);
}

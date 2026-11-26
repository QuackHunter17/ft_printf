/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:34:33 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/25 13:49:23 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "printing_functs/print_functs.h"
#include "libft/libft.h"

char	*extract_format(const char *, size_t);
size_t	write_function(char *substr, size_t num_prin, va_list *ap);
int	ft_printf(const char *, ...);

#endif

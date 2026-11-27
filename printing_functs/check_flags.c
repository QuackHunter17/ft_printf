/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 10:20:07 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/26 14:41:23 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functs.h"

static int	check_if_flag(char c)
{
	if (c == '-' || c == '0' || c == '#' || c == '+' || c == ' ')
		return (1);
	return (0);
}

static int	*assign_flags(char c, int *flags)
{
	if (c == '-')
		flags[0] = 1;
	else if (c == '0')
		flags[1] = 1;
	else if (c == '#')
		flags[2] = 1;
	else if (c == '+')
		flags[3] = 1;
	else if (c == ' ')
		flags[4] = 1;
	return (flags);
}

static void	fill_with_zero(int *flags)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		flags[i] = 0;
		i++;
	}
}
int	*check_flags(char *s)
{
	size_t	i;
	int	*flags;

	flags = malloc(sizeof(int) * 7);
	if (!flags)
		return (NULL);
	fill_with_zero(flags);
	flags[6] = -1;
	i = 1;
	while (check_if_flag(s[i]))
	{
		flags = assign_flags(s[i], flags);
		i++;
	}
	flags[5] = ft_atoi(&s[i]);
	while (ft_isdigit((int)s[i]))
		i++;
	if (s[i] == '.')
	{
		i++;
		flags[6] = ft_atoi(&s[i]);
	}
	return (flags);
}


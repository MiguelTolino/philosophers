/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:16:39 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/12 14:30:10 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	else
		return (1);
}

static int	is_negative(int negative)
{
	if (negative != 0)
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}

int	ft_atoi(const char *str)
{
	long int	num;
	int			negative;

	num = 0;
	negative = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		num = num * 10 + *str - 48;
		if (num * is_negative(negative) > 2147483647)
			return (-1);
		if (num * is_negative(negative) < -2147483648)
			return (0);
		str++;
	}
	return ((int)(num * is_negative(negative)));
}

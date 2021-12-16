/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:06:42 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/15 14:16:14 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	*parse_arguments(int num, char **argv)
{
	int	i;
	int	*params;

	i = 1;
	params = (int *)malloc(sizeof(int) * num);
	while (argv[i])
	{
		params[i - 1] = ft_atoi(argv[i]);
		if (params[i - 1] <= 0)
			return (NULL);
		i++;
	}
	return (params);
}

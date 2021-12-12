/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:06:42 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/12 14:30:40 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	*parse_arguments(int num, char **argv)
{
	int	i;
	int	*option;

	i = 1;
	option = (int *)malloc(sizeof(int) * num);
	while (argv[i])
	{
		option[i - 1] = ft_atoi(argv[i]);
		if (option[i - 1] <= 0)
			return (NULL);
		i++;
	}
	return (option);
}

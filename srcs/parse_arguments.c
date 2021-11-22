/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:06:42 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/22 11:59:50 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_arguments(char **argv, unsigned int **option)
{
	int	i;
	int	num;

	i = 1;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		//printf("%i\n", num);
		if (num < 0)
			return (-1);
		*option[i - 1] = (unsigned int)(num);
		printf("%i\n", *option[i - 1]);
		i++;
	}
	return (0);
}

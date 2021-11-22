/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:06:19 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/22 13:01:18 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
//	t_philo philo;
	int	*option;

	if ((argc < 5 || argc > 6))
		return (-1);
	option = parse_arguments(argc - 1, argv);
	if (!option)
		return(-1);
	test(option, argc);
	return (0);
}
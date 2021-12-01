/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:56:07 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/01 12:38:20 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int destroy_struct(t_struct p)
{
	int i;

	i = 0;
	while (i < p.option[NUM_OF_PHILOS])
	{
		if (pthread_join(p.philo[i].th, NULL) != 0)
			return (1);
		pthread_mutex_destroy(&p.fork[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&p.print_mutex);
	free(p.fork);
	free(p.philo);
	free(p.option);
	free(p.turn_id);
	return (0);
}
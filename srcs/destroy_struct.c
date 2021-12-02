/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:56:07 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/02 17:26:53 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int destroy_struct(t_fork *fork, t_philo *philo)  
{
	int i;

	i = 0;
	while (i < philo->data->option[NUM_OF_PHILOS])
	{
		if (pthread_join(philo[i].th, NULL) != 0)
			return (1);
		pthread_mutex_destroy(&fork[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&philo->data->print_mutex);
	free(fork);
	free(philo);
	//free(philo[0].turn_id); //FIXME: Pointer must be freed
	return (0);
}
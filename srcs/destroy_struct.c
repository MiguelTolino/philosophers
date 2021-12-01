/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:56:07 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/01 19:27:38 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int destroy_struct(t_philo *philo, t_fork *fork, int *option)  
{
	int i;

	i = 0;
	while (i < option[NUM_OF_PHILOS])
	{
		if (pthread_join(philo[i].th, NULL) != 0)
			return (1);
		pthread_mutex_destroy(&fork[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&philo->print_mutex);
	free(fork);
	free(philo);
	free(option);
	//free(philo[0].turn_id); //FIXME: Pointer must be freed
	return (0);
}
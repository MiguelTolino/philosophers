/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:56:07 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/12 21:54:13 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_struct(t_fork *fork, t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < philo->data->option[NUM_OF_PHILOS])
	{
		if (pthread_join(philo[i].th, NULL) != 0)
			return (1);
		pthread_mutex_destroy(&fork[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&philo->data->print_mutex);
	pthread_mutex_destroy(&philo->data->access_mutex);
	pthread_mutex_destroy(&philo->data->access_mutex);
	free(fork);
	free(philo);
	free(data->turn_id);
	free(data->option);
	return (0);
}

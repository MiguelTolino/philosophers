/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:56:07 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/17 00:07:14 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_struct(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < philo->data->params[NUM_OF_PHILOS])
	{
		if (pthread_join(philo[i].th, NULL) != 0)
			return (1);
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->data->print_mutex);
	pthread_mutex_destroy(&philo->data->access_mutex);
	free(data->fork);
	free(philo);
	free(data->params);
	return (0);
}

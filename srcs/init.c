/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:20:45 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/17 00:07:01 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_data(t_data *data)
{
	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->params[NUM_OF_PHILOS]);
	data->n_eaters = data->params[NUM_OF_PHILOS] / NUM_OF_FORKS;
	data->all_ate = 0;
	data->dieded = 0;
	if (pthread_mutex_init(&data->print_mutex, NULL)
		|| pthread_mutex_init(&data->access_mutex, NULL))
		return (1);
	return (0);
}

int	init(t_philo **philo, t_data *data)
{
	int		i;
	t_philo	*p;

	p = *philo;
	i = 0;
	p = (t_philo *)malloc(sizeof(t_philo) * data->params[NUM_OF_PHILOS]);
	if (set_data(data))
		return (1);
	while (i < data->params[NUM_OF_PHILOS])
	{
		p[i].die = 0;
		p[i].has_ate = 0;
		p[i].id = i + 1;
		p[i].data = data;
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (1);
		p[i].left_fork = i;
		if (i == data->params[NUM_OF_PHILOS] - 1)
			p[i].right_fork = 0;
		else
			p[i].right_fork = i + 1;
		i++;
	}
	*philo = p;
	return (0);
}

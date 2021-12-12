/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:20:45 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/12 21:53:49 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	*turn(int *option)
{
	int	num;
	int	i;
	int	first;
	int	*turn_id;

	i = 0;
	first = 1;
	num = option[NUM_OF_PHILOS] / NUM_OF_FORKS;
	turn_id = (int *)malloc(sizeof(int) * num);
	while (i < num)
	{
		turn_id[i] = first;
		first += 2;
		i++;
	}
	return (turn_id);
}

int	init(t_fork **fork, t_philo **philo, t_data *data)
{
	int		i;
	t_fork	*f;
	t_philo	*p;

	f = *fork;
	p = *philo;
	i = 0;
	p = (t_philo *)malloc(sizeof(t_philo) * data->option[NUM_OF_PHILOS]);
	f = (t_fork *)malloc(sizeof(t_fork) * data->option[NUM_OF_PHILOS]);
	data->turn_id = turn(data->option);
	data->n_eaters = data->option[NUM_OF_PHILOS] / NUM_OF_FORKS;
	data->all_ate = 0;
	data->deaded = 0;
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->access_mutex, NULL);
	pthread_mutex_init(&data->eat_mutex, NULL);
	while (i < data->option[NUM_OF_PHILOS])
	{
		p[i].die = 0;
		p[i].has_ate = 0;
		p[i].id = i + 1;
		p[i].data = data;
		f[i].id = i + 1;
		pthread_mutex_init(&f[i].mutex, NULL);
		i++;
	}
	i = 0;
	while (i < data->option[NUM_OF_PHILOS])
	{
		p[i].left_fork = f[i];
		if (i == data->option[NUM_OF_PHILOS] - 1)
			p[i].right_fork = f[0];
		else
			p[i].right_fork = f[i + 1];
		i++;
	}
	*philo = p;
	*fork = f;
	return (0);
}

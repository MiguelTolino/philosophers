/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:34:37 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/16 21:33:28 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eats(t_philo *p)
{
	t_data	*data;

	data = p->data;
	pthread_mutex_lock(&data->fork[p->left_fork]);
	print_log("has taken left fork", p->id, data);
	pthread_mutex_lock(&data->fork[p->right_fork]);
	print_log("has taken right fork", p->id, data);
	pthread_mutex_lock(&data->eat_mutex);
	print_log("is eating", p->id, data);
	p->time_last_meal = get_time();
	pthread_mutex_unlock(&data->eat_mutex);
	smart_sleep(data->params[TIME_TO_EAT], data);
	p->has_ate++;
	pthread_mutex_unlock(&data->fork[p->left_fork]);
	pthread_mutex_unlock(&data->fork[p->right_fork]);
}

void	death_checker(t_philo *philo)
{
	t_data		*data;
	int			i;
	long long	time;

	data = philo->data;
	while (!(data->all_ate) && !(data->dieded))
	{
		i = 0;
		while (i < data->params[NUM_OF_PHILOS] && !(data->dieded))
		{
			pthread_mutex_lock(&data->access_mutex);
			time = diff_time(philo[i].time_last_meal, get_time());
			if (time > data->params[TIME_TO_DIE])
			{
				print_log("died", philo[i].id, data);
				data->dieded = 1;
			}
			pthread_mutex_unlock(&data->access_mutex);
			i++;
		}
		usleep(100);
		if (data->dieded)
			break ;
 		i = 0;
/* 		while (data->params[NUM_OF_TIMES_EAT] > 0 && i < data->params[NUM_OF_PHILOS] && philo[i].has_ate >= data->params[NUM_OF_TIMES_EAT])
			i++;
		if (i == data->params[NUM_OF_PHILOS])
			data->all_ate = 1;
	} */
	}
}

	//FIX: Si han comido las sufientes veces || BIG NUMBER OF PhiLOS

void	*eat_think_sleep(void *philo)
{
	t_philo	*p;
	t_data	*data;

	p = (t_philo *)philo;
	data = p->data;
	if (p->id % 2 == 0)
		usleep(100);
	while (!data->dieded)
	{
		philo_eats(p);
		if (data->all_ate)
			break ;
		print_log("is sleeping", p->id, data);
		smart_sleep(data->params[TIME_TO_SLEEP], data);
		print_log("is thinking", p->id, data);
	}
	return (NULL);
}

int	create_philos(t_philo *philo)
{
	int	i;

	i = 0;
	philo->data->timestamp = get_time();
	while (i < philo->data->params[NUM_OF_PHILOS])
	{
		if (pthread_create(&(philo[i].th), NULL,
				&eat_think_sleep, &(philo[i])) != 0)
			return (1);
		philo[i].time_last_meal = get_time();
		i++;
	}
	death_checker(philo);
	return (0);
}

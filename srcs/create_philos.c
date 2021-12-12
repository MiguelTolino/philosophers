/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:34:37 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/12 23:15:03 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	increment_turn(t_data *data, t_philo *p)
{
	int	i;
	int	len;

	i = 0;
	len = data->n_eaters;
	pthread_mutex_lock(&data->access_mutex);
	while (i < len)
	{
		if (p->id == data->turn_id[i])
		{
			data->turn_id[i]++;
			if (data->turn_id[i] == (data->option[NUM_OF_PHILOS] + 1))
				data->turn_id[i] = 1;
			break ;
		}
		i++;
	}
	pthread_mutex_unlock(&data->access_mutex);
}

void	philo_eats(t_philo *p)
{
	t_data	*data;

	data = p->data;
	pthread_mutex_lock(&p->left_fork.mutex);
	print_log("has taken left fork", p->id, data);
	pthread_mutex_lock(&p->right_fork.mutex);
	print_log("has taken right fork", p->id, data);
	print_log("is eating", p->id, data);
	p->time_last_meal = get_time();
	smart_sleep(data->option[TIME_TO_EAT], data);
	p->has_ate++;
	pthread_mutex_unlock(&p->left_fork.mutex);
	pthread_mutex_unlock(&p->right_fork.mutex);
	increment_turn(data, p);
}

void	death_checker(t_philo *philo)
{
	t_data		*data;
	int			i;
	long long	time;

	data = philo->data;
	while (!(data->all_ate))
	{
		i = 0;
		while (i < data->option[NUM_OF_PHILOS] && !(data->deaded))
		{
			pthread_mutex_lock(&data->access_mutex);
			time = diff_time(philo[i].time_last_meal, get_time());
			if (time > data->option[TIME_TO_DIE])
			{
				print_log("died", philo[i].id, data);
				data->deaded = 1;
			}
			pthread_mutex_unlock(&data->access_mutex);
			i++;
		}
		usleep(100);
		if (data->deaded)
			break ;
 		i = 0;
/* 		while (data->option[NUM_OF_TIMES_EAT] > 0 && i < data->option[NUM_OF_PHILOS] && philo[i].has_ate >= data->option[NUM_OF_TIMES_EAT])
			i++;
		if (i == data->option[NUM_OF_PHILOS])
			data->all_ate = 1;
	} */
	}
}

int	check_turn(t_data *data, t_philo p)
{
	int	i;
	int	len;

	len = data->n_eaters;
	i = 0;
	while (i < len)
	{
		if (p.id == data->turn_id[i])
			return (1);
		i++;
	}
	return (0);
}

	//FIX: Si han comido las sufientes veces || BIG NUMBER OF PhiLOS

void	*eat_think_sleep(void *philo)
{
	t_philo	*p;
	t_data	*data;

	p = (t_philo *)philo;
	data = p->data;
	p->t1 = get_time();
	while (!data->deaded)
	{
		if (check_turn(data, *p))
		{
			philo_eats(p);
			if (data->all_ate)
				break ;
			print_log("is sleeping", p->id, data);
			smart_sleep(data->option[TIME_TO_SLEEP], data);
			print_log("is thinking", p->id, data);
		}
	}
	return (NULL);
}

int	create_philos(t_philo *philo)
{
	int	i;

	i = 0;
	philo->data->timestamp = get_time();
	while (i < philo->data->option[NUM_OF_PHILOS])
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

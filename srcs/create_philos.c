/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:34:37 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/12 14:26:05 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* int check_die(t_philo p, t_data *data)
{
	long long time;
	// Si (Timetodie + t1) - timetolastmeal < 0
	time = diff_time(p.time_last_meal - p.t1, data->option[TIME_TO_DIE]);
	if (time < 0)
		return (1);
	return (0);
} */
/*

int *turn2(int *option)
{
	int num;
	int i;
	int first;
	int *turn_id;

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
*/

void increment_turn(t_data *data, t_philo p)
{
	int i;
	int len;

	i = 0;
	len = data->n_eaters;
	pthread_mutex_lock(&data->access_mutex);
	while (i < len)
	{
		if (p.id == data->turn_id[i])
		{
			data->turn_id[i]++;
			if (data->turn_id[i] == (data->option[NUM_OF_PHILOS] + 1))
				data->turn_id[i] = 1;
			break;
		}
		i++;
	}
	pthread_mutex_unlock(&data->access_mutex);
}

 int check_turn(t_data *data, t_philo p)
{
	int i;
	int len;

	//pthread_mutex_lock(&data->access_mutex);
	len = data->n_eaters;
	i = 0;
	while (i < len)
	{
		if (p.id == data->turn_id[i])
			return (1);
		i++;
	}
	//pthread_mutex_unlock(&data->access_mutex);
	return (0);
}

/* 1. 
*/

 void *eat_think_sleep(void *philo)
{
	t_philo p;
	t_data *data;

	p = *(t_philo*)philo;
	data = p.data;
//	while (!p.die && data->all_ate)	//Crear funciones check_die y check_all_eat y increment turn | Iterar usleep en tiempos cortos
	while (!p.die)
	{
		if (check_turn(data, p))
		{
			pthread_mutex_lock(&p.left_fork.mutex);
			print_log("has taken left fork", diff_time(p.t1, get_time()), p.id, data);
			pthread_mutex_lock(&p.right_fork.mutex);
			print_log("has taken right fork", diff_time(p.t1, get_time()), p.id, data);
			p.time_last_meal = get_time();
			print_log("is eating", diff_time(p.t1, p.time_last_meal), p.id, data);
			usleep(data->option[TIME_TO_EAT] * 1000);
			increment_turn(data, p);
			pthread_mutex_unlock(&p.left_fork.mutex);
			pthread_mutex_unlock(&p.right_fork.mutex);
			print_log("is sleeping", diff_time(p.t1, get_time()), p.id, data);
			usleep(data->option[TIME_TO_SLEEP] * 1000);
			print_log("is thinking", diff_time(p.t1, get_time()), p.id, data);
		}
	}
	return (NULL);
}

int	create_philos(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->data->option[NUM_OF_PHILOS])
	{
		philo[i].t1 = get_time();
		if (pthread_create(&philo[i].th, NULL, &eat_think_sleep, &philo[i]) != 0)
			return (1);
		i++;
	}
	//death_checker
	return (0);
}
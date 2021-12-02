/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:34:37 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/02 11:31:47 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_die(t_philo p)
{
	long long time;

	time = diff_time(p.time_last_meal, p.option[TIME_TO_DIE]);
	if (time < 0)
		return (1);
	return (0);
}

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

void increment_turn(t_philo *p)
{
	int i;
	int len;

	i = 0;
	len = sizeof(p->turn_id) / sizeof(p->turn_id[0]);
	while (i < len)
	{
		if (p->turn_id[i] == p->option[NUM_OF_PHILOS])
		{
			p->turn_id[i] = 1;
			break;
		}
		p->turn_id[i] += 1;
		i++;
	}
}

int check_turn(int id, int *turn_id)
{
	int i;
	int len;

	i = 0;
	len = sizeof(turn_id) / sizeof(turn_id[0]);
	while (i < len)
	{
		if (id == turn_id[i])
			return (1);
		i++;
	}
	return (0);
}

void *eat_think_sleep(void *philo)
{
	t_philo p;

	p = *(t_philo *)philo;
	while(!p.die)
	{
 	if (check_turn(p.id, p.turn_id) && !p.has_ate)
	{
		pthread_mutex_lock(&p.left_fork.mutex);
		print_log("has taken a fork", diff_time(p.t1,get_time()), p.id, &p);
		pthread_mutex_lock(&p.right_fork.mutex);
		print_log("has taken a fork", diff_time(p.t1, get_time()), p.id, &p);
		print_log("is eating", diff_time(p.t1, get_time()), p.id, &p);
		usleep(p.option[TIME_TO_EAT] * 1000);
		pthread_mutex_unlock(&p.left_fork.mutex);
		pthread_mutex_unlock(&p.right_fork.mutex);
		p.has_ate = 1;
		p.time_last_meal = get_time();
		pthread_mutex_lock(&p.print_mutex);
		increment_turn(&p);
		pthread_mutex_unlock(&p.print_mutex);
		print_log("is sleeping", diff_time(p.t1, get_time()), p.id, &p);
		usleep(p.option[TIME_TO_SLEEP] * 1000);
		print_log("is thinking", diff_time(p.t1, get_time()), p.id, &p);
	}
		p.die = check_die(p);
	}
	pthread_mutex_lock(&p.print_mutex);
	if (p.die)
	{
		print_log("has dead", diff_time(p.t1, get_time()), p.id, &p);
	}
	pthread_mutex_unlock(&p.print_mutex);
	
}

int	create_philos(t_philo *philo)
{
	int i;
	
	i = 0;
	while (i < philo->option[NUM_OF_PHILOS])
	{
		philo[i].t1 = get_time();
		if (pthread_create(&philo[i].th, NULL, &eat_think_sleep, &philo[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:34:37 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/01 20:52:30 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void increment_turn(int *turn_id)
{
	int i;
	int len;

	i = 0;
	len = sizeof(turn_id) / sizeof(turn_id[0]);
	while (i < len)
	{
		turn_id[i] += 1;
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
	t_philo *p;

	p = (t_philo *)philo;
/* 	if (check_turn(p->id, p->turn_id))
	{
		printf("ID: %i\n", p->id); */
/* 		pthread_mutex_lock(&p->left_fork.mutex);
		//print_log("has taken a fork", diff_time(p->t1, get_time()), p->id, p);
		pthread_mutex_lock(&p->right_fork.mutex);
		//print_log("has taken a fork", diff_time(p->t1, get_time()), p->id, p);
		pthread_mutex_unlock(&p->left_fork.mutex);
		pthread_mutex_unlock(&p->right_fork.mutex); */
}

int	create_philos(t_philo *philo)
{
	int i;
	
	i = 0;
	while (i < philo->option[NUM_OF_PHILOS])
	{
		//philo->t1 = get_time();
		if (pthread_create(&philo[i].th, NULL, &eat_think_sleep, &philo[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
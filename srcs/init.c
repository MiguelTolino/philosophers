/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:20:45 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/01 19:05:45 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define NUM_OF_FORKS 2

int *turn(int *option)
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

int init(int *option, t_philo **philo, t_fork **fork)
{
	int i;
	int *turn_id;
	t_philo *philo_aux;
	t_fork *fork_aux;

	i = 0;
	philo_aux = *philo;
	fork_aux = *fork;
	philo_aux = (t_philo *)malloc(sizeof(t_philo) * option[NUM_OF_PHILOS]);
	fork_aux = (t_fork *)malloc(sizeof(t_fork) * option[NUM_OF_PHILOS]);
	turn_id = turn(option);
	while (i < option[NUM_OF_PHILOS])
	{
		philo_aux[i].all_ate = 0;
		philo_aux[i].has_ate = 0;
		philo_aux[i].id = i + 1;
		philo_aux[i].option = option;
 		pthread_mutex_init(&philo_aux[i].print_mutex, NULL);
		philo_aux[i].turn_id = turn_id;
		fork_aux[i].id = i + 1;
		pthread_mutex_init(&fork_aux[i].mutex, NULL);
		i++;
	}
	i = 0;
	while (i < option[NUM_OF_PHILOS])
	{
		philo_aux[i].left_fork = fork_aux[i];
		if (i == option[NUM_OF_PHILOS] - 1)
			philo_aux[i].right_fork = fork_aux[0];
		else
			philo_aux[i].right_fork = fork_aux[i + 1];
		i++;
	}
	*philo = philo_aux;
	*fork = fork_aux;
	return (0);
}
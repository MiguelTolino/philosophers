/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:34:37 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/01 15:04:59 by mmateo-t         ###   ########.fr       */
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

void *eat_think_sleep(void *p)
{
	t_philo *v;

	v = (t_philo *)p;
	if (v->id == 1)
	{
		printf("Hola mundo\n");
	}
	
}

int	create_philos(t_struct *p)
{
	int i;
	
	i = 0;
	while (i < p->option[NUM_OF_PHILOS])
	{
		if (pthread_create(&p->philo[i].th, NULL, &eat_think_sleep, &p->philo[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
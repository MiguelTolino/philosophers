/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:20:45 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/01 10:50:34 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init(t_struct *p)
{
	int i;

	i = 0;
	p->all_ate = 0;
	p->philo = (t_philo *)malloc(sizeof(t_philo) * p->option[NUM_OF_PHILOS]);
	p->fork = (t_fork *)malloc(sizeof(t_fork) * p->option[NUM_OF_PHILOS]);
	while (i < p->option[NUM_OF_PHILOS])
	{
		p->philo[i].has_ate = 0;
		p->philo[i].id = i + 1;
		p->fork[i].id = i;
		pthread_mutex_init(&p->fork[i].mutex, NULL);
		i++;
	}
	return (0);
}
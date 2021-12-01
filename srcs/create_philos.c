/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:34:37 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/01 11:24:06 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *eat_think_sleep(void *p)
{
	t_struct *v;

	v = (t_struct *)p;
	pthread_mutex_lock(&v->fork[0].mutex);
	printf("Hello World\n");
	printf("%i\n", v->option[NUM_OF_PHILOS]);
	pthread_mutex_unlock(&v->fork[0].mutex);
}

int	create_philos(t_struct *p)
{
	int i;
	
	i = 0;
	while (i < p->option[NUM_OF_PHILOS])
	{
		if (pthread_create(&p->philo[i].th, NULL, &eat_think_sleep, p) != 0)
			return (1);
		i++;
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:08:35 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/16 20:53:15 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

	void test4(t_philo *philo)
	{
		int i = 0;
		while (i < philo->data->params[NUM_OF_PHILOS])
		{
			printf("PhiloID: %i\n", philo[i].id);
			printf("Has ate: %i\n", philo[i].has_ate);
			printf("NUM_OF_PHILOS: %i\n", philo->data->params[0]);
			printf("TIME_TO_DIE: %i\n", philo->data->params[TIME_TO_DIE]);
			printf("TIME_TO_EAT: %i\n", philo->data->params[TIME_TO_EAT]);
			printf("TIME_TO_SLEEP: %i\n", philo->data->params[TIME_TO_SLEEP]);
			printf("EAT_TIME: %i\n", philo->data->params[NUM_OF_TIMES_EAT]);
			printf("\n");
			i++;
		}
	}

void test(t_philo *philo)
{
	//test2(p);
	//test3(p);
	test4(philo);
	//test_ind(philo);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:08:35 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/02 17:20:50 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

	void test4(t_philo *philo)
	{
		int i = 0;
		int j = 0;
		int num = philo->data->option[NUM_OF_PHILOS] / 2;
		
		while (i < philo->data->option[NUM_OF_PHILOS])
		{
			j = 0;
			printf("Philo %i\n", i + 1);
			printf("Has ate: %i\n", philo[i].has_ate);
			printf("ID: %i\n", philo[i].id);
			printf("NUM_OF_PHILOS: %i\n", philo->data->option[0]);
			printf("TIME_TO_DIE: %i\n", philo->data->option[TIME_TO_DIE]);
			printf("TIME_TO_EAT: %i\n", philo->data->option[TIME_TO_EAT]);
			printf("TIME_TO_SLEEP: %i\n", philo->data->option[TIME_TO_SLEEP]);
			printf("LeftForkID: %i\n", philo[i].left_fork.id);
			printf("RightForkID: %i\n", philo[i].right_fork.id);
			while (j < num)
			{
				printf("TurnID%i: %i\n", j, philo->data->turn_id[j++]);
			}
			printf("\n");
			i++;
		}
	}

void test_ind(t_philo *philo)
{
	int j;
		
	j = 0;
	printf("PhiloID %i\n", philo->id);
	printf("Has ate: %i\n", philo->has_ate);
	printf("LeftForkID: %i\n", philo->left_fork.id);
	printf("RightForkID: %i\n", philo->right_fork.id);
	printf("\n");
}

void test(t_philo *philo)
{
	//test2(p);
	//test3(p);
	test4(philo);
	//test_ind(philo);
}


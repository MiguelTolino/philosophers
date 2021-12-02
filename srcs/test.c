/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:08:35 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/01 21:06:00 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void test4(t_philo *philo)
{
	int i = 0;
	int j = 0;
	int num = philo[0].option[NUM_OF_PHILOS] / 2;
	
	printf("NUM_OF_PHILOS, %i\n", philo[0].option[ NUM_OF_PHILOS]);

	while (i < philo[0].option[ NUM_OF_PHILOS])
	{
		j = 0;
		printf("Philo %i\n", i);
		printf("All ate: %i\n", philo[i].all_ate);
		printf("Has ate: %i\n", philo[i].has_ate);
		printf("ID: %i\n", philo[i].id);
		printf("Option: %i\n", philo[i].option[0]);
 		printf("LeftForkID: %i\n", philo[i].left_fork.id);
		printf("RightForkID: %i\n", philo[i].right_fork.id);
		while (j < num)
		{
			printf("TurnID%i: %i\n", j, philo[i].turn_id[j++]);
		}		
		printf("\n");
		i++;
	}
}

void test_ind(t_philo *philo)
{
	int j;
	int num = philo->option[NUM_OF_PHILOS] / 2;
	
	j = 0;
	printf("PhiloID %i\n", philo->id);
	printf("All ate: %i\n", philo->all_ate);
	printf("Has ate: %i\n", philo->has_ate);
	printf("Option: %i\n", philo->option[0]);
	printf("LeftForkID: %i\n", philo->left_fork.id);
	printf("RightForkID: %i\n", philo->right_fork.id);
	while (j < num)
	{
		printf("TurnID%i: %i\n", j, philo->turn_id[j++]);
	}		
	printf("\n");
}

void test(t_philo *philo)
{
	//test2(p);
	//test3(p);
	//test4(philo);
	test_ind(philo);
}


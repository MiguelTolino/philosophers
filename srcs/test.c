/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:08:35 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/01 19:06:29 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void test2(t_struct p)
{
	int i = 0;
	int num = p.option[NUM_OF_PHILOS] / 2;
	while (i < num)
	{
		printf("%i\n", p.turn_id[i]);
		i++;
	}
}

void test3(t_struct p)
{
	int i = 0;
	while (i < p.option[NUM_OF_PHILOS])
	{
		printf("Philo Has ate?:%i\t", p.philo[i].has_ate);
		printf("PhiloID:%i\n", p.philo[i].id);
		printf("ForkID:%i\n", p.fork[i].id);
		i++;
	}
	printf("All ate? :%i\n", p.all_ate);
}

void test4(t_philo *philo)
{
	int i = 0;
	
	while (i < philo[0].option[ NUM_OF_PHILOS])
	{
		printf("Philo %i\n", i);
		printf("All ate: %i\n", philo[i].all_ate);
		printf("Has ate: %i\n", philo[i].has_ate);
		printf("ID: %i\n", philo[i].id);
		printf("Option: %i\n", philo[i].option[0]);
 		printf("LeftForkID: %i\n", philo[i].left_fork.id);
		printf("RightForkID: %i\n", philo[i].right_fork.id);
		printf("TurnID: %i\n", philo[i].turn_id[0]);
		printf("\n");
		i++;
	}
}

void test(t_philo *philo)
{
	//test2(p);
	//test3(p);
	test4(philo);
}


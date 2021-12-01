/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:08:35 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/01 12:45:28 by mmateo-t         ###   ########.fr       */
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



void test(t_struct p)
{
	test2(p);
	//test3(p);
}


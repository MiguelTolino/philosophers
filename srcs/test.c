/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:08:35 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/01 10:52:51 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void test(t_struct p)
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
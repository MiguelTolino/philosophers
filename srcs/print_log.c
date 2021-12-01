/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:31:57 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/01 20:45:00 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_log(char *str, long timestamp, int philo_nb, t_philo *p)
{
	pthread_mutex_lock(&p->print_mutex);
	printf("%li ms %i %s\n", timestamp, philo_nb, str);
	pthread_mutex_unlock(&p->print_mutex);
}
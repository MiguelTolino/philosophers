/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:31:57 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/12 14:35:12 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_log(char *str, long long timestamp, int philo_nb, t_data *data)
{
	pthread_mutex_lock(&data->print_mutex);
	printf("%lli ms %i %s\n", timestamp, philo_nb, str);
	pthread_mutex_unlock(&data->print_mutex);
}

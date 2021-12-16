/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:31:57 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/15 14:25:30 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_log(char *str, int philo_nb, t_data *data)
{
	pthread_mutex_lock(&data->print_mutex);
	if (!data->dieded)
		printf("%lli ms %i %s\n", get_time() - data->timestamp, philo_nb, str);
	pthread_mutex_unlock(&data->print_mutex);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:31:57 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/12 21:41:11 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_log(char *str, int philo_nb, t_data *data)
{
	pthread_mutex_lock(&data->print_mutex);
	if (!data->deaded)
		printf("%lli ms %i %s\n", get_time() - data->timestamp, philo_nb, str);
	pthread_mutex_unlock(&data->print_mutex);
}

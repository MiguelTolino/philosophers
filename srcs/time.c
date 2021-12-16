/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:50:16 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/15 14:25:30 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Long long signed integer type
[−9,223,372,036,854,775,807, +9,223,372,036,854,775,807] range.
64	(%lli or %lld) */

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	diff_time(long long t1, long long t2)
{
	return (t2 - t1);
}

void	smart_sleep(long long time, t_data *data)
{
	long long	i;

	i = get_time();
	while (!(data->dieded))
	{
		if (diff_time(i, get_time()) >= time)
			break ;
		usleep(50);
	}
}

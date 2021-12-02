/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:06:19 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/02 17:25:41 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_fork *fork;
	t_philo *philo;
	t_data data;

	if ((argc < 5 || argc > 6))
		return (throw_error("Error: Number of arguments invalid\n"));
	data.option = parse_arguments(argc - 1, argv);
	if (!data.option)
		return(throw_error("Error: Some arguments failed\n"));
	if (init(&fork, &philo, &data))
		return (throw_error("Error: Could not initializate threads"));
 	if (create_philos(philo))
		return(throw_error("Error: There was an error"));
  	if (destroy_struct(fork, philo))
		return (throw_error("Error: A problem in joins threads occurs"));
	return (0);
}
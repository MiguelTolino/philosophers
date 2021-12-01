/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:06:19 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/01 11:16:23 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_struct p;

	if ((argc < 5 || argc > 6))
		return (throw_error("Error: Number of arguments invalid\n"));
	p.option = parse_arguments(argc - 1, argv);
	if (!p.option)
		return(throw_error("Error: Some arguments failed\n"));
	if (init(&p))
		return (throw_error("Error: Could not initializate threads"));
	if (create_philos(&p))
		return(throw_error("Error: There was an error"));
	if (destroy_struct(p))
		return (throw_error("Error: A problem in joins threads occurs"));
	//test(p);
	return (0);
}
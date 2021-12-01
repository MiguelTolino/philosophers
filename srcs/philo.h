/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:07:08 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/01 14:23:12 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>


# define NUM_OF_PHILOS 0
# define TIME_TO_DIE 1
# define TIME_TO_EAT 2
# define TIME_TO_SLEEP 3
# define NUM_OF_TIMES_EAT 4

//Log message
#define FORK "has taken a fork"
#define EAT "is eating"
#define DIE "die"
#define THINK "is thinking"
#define SLEEP "is sleeping"

typedef struct t_philo
{
	pthread_t	th;
	int	id;
	int has_ate;
} t_philo;

typedef struct t_fork
{
	int	id;
	pthread_mutex_t mutex;
}	t_fork;

typedef struct t_struct
{
	t_philo *philo;
	t_fork	*fork;
	int		*option;
	int		all_ate;
	pthread_mutex_t print_mutex;
	int *turn_id;
}	t_struct;

int	ft_atoi(const char *str);
size_t ft_strlen(const char *str);
int	throw_error(char *str);
int	create_philos(t_struct *p);
int	*parse_arguments(int num, char **argv);
void test(t_struct p);
int init(t_struct *p);
int destroy_struct(t_struct p);
void print_log(char *str, long timestamp, int philo_nb, t_struct p);
long diff_time(struct timeval *t1, struct timeval *t2);

#endif
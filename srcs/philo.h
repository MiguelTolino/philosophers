/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:07:08 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/12 20:51:21 by mmateo-t         ###   ########.fr       */
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

# define NUM_OF_FORKS 2

//Log message
# define FORK "has taken a fork"
# define EAT "is eating"
# define DIE "die"
# define THINK "is thinking"
# define SLEEP "is sleeping"

typedef struct t_data
{
	int				all_ate;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	access_mutex;
	int				*turn_id;
	int				n_eaters;
	int				*option;
	int				deaded;
	long long		timestamp;
}	t_data;

typedef struct t_fork
{
	int				id;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct t_philo
{
	pthread_t	th;
	int			id;
	int			has_ate;
	t_fork		left_fork;
	t_fork		right_fork;
	long long	t1;
	long long	time_last_meal;
	int			die;
	t_data		*data;
}	t_philo;

int			ft_atoi(const char *str);
size_t		ft_strlen(const char *str);
int			throw_error(char *str);
int			create_philos(t_philo *philo);
int			*parse_arguments(int num, char **argv);
void		test(t_philo *philo);
int			init(t_fork **fork, t_philo **philo, t_data *data);
int			destroy_struct(t_fork *fork, t_philo *philo, t_data *data);
void		print_log(char *str, int philo_nb, t_data *data);
long long	diff_time(long long t1, long long t2);
long long	get_time(void);
int			*turn2(int *option);
void		smart_sleep(long long time, t_data *data);

#endif
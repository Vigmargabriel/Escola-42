/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:04:48 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/19 17:04:50 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

/* Estruturas */
typedef struct s_data	t_data;

typedef struct s_philo
{
	int			id;
	int			meals_eaten;
	long long	last_meal;
	int			left_fork;
	int			right_fork;
	pthread_t	thread_id;
	t_data		*data;
}	t_philo;

typedef struct s_data
{
	int				number_of_philosophers;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				must_eat;
	long long		start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	int				simulation_over;
	pthread_mutex_t	state_lock;
}	t_data;

/* init.c */
int			init_all(t_data *data);

/* threads.c */
int			start_simulation(t_data *data);
int			check_sim(t_data *d);

/* philosophers.c */
void		*philo_routine(void *arg);
void		pickup_forks(t_philo *p);
void		philo_eat(t_philo *p);
void		philo_sleep(t_philo *p);
void		philo_think(t_philo *p);

/* simulation.c */
int			monitor_simulation(t_data *data);

/* utils.c */
long long	get_time(void);
void		ft_usleep(long long time_in_ms, t_data *data);
void		safe_print(t_data *d, int id, char *msg);

/* Função de limpeza */
void		cleanup(t_data *data);

#endif

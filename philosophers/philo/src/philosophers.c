/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+        */
/*   Created: 2025/02/19 17:07:45 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/19 17:07:48 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <unistd.h>

void	pickup_forks(t_philo *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(&p->data->forks[p->right_fork]);
		safe_print(p->data, p->id, "has taken a fork");
		pthread_mutex_lock(&p->data->forks[p->left_fork]);
		safe_print(p->data, p->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&p->data->forks[p->left_fork]);
		safe_print(p->data, p->id, "has taken a fork");
		pthread_mutex_lock(&p->data->forks[p->right_fork]);
		safe_print(p->data, p->id, "has taken a fork");
	}
}

void	philo_eat(t_philo *p)
{
	pthread_mutex_lock(&p->data->state_lock);
	p->last_meal = get_time();
	pthread_mutex_unlock(&p->data->state_lock);
	safe_print(p->data, p->id, "is eating");
	ft_usleep(p->data->time_to_eat, p->data);
	p->meals_eaten++;
}

void	philo_sleep(t_philo *p)
{
	safe_print(p->data, p->id, "is sleeping");
	ft_usleep(p->data->time_to_sleep, p->data);
}

void	philo_think(t_philo *p)
{
	safe_print(p->data, p->id, "is thinking");
	ft_usleep(10, p->data);
}

void	*philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->data->number_of_philosophers == 1)
	{
		safe_print(p->data, p->id, "has taken a fork");
		ft_usleep(p->data->time_to_die, p->data);
		return (NULL);
	}
	if (p->id % 2 == 0)
		ft_usleep(100, p->data);
	while (!check_sim(p->data))
	{
		pickup_forks(p);
		philo_eat(p);
		pthread_mutex_unlock(&p->data->forks[p->left_fork]);
		pthread_mutex_unlock(&p->data->forks[p->right_fork]);
		philo_sleep(p);
		philo_think(p);
	}
	return (NULL);
}

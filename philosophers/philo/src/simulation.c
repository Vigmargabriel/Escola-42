/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+        */
/*   Created: 2025/02/19 17:07:19 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/19 17:07:21 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

static int	check_death(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->number_of_philosophers)
	{
		pthread_mutex_lock(&d->state_lock);
		if ((get_time() - d->philos[i].last_meal) > d->time_to_die)
		{
			d->simulation_over = 1;
			pthread_mutex_unlock(&d->state_lock);
			pthread_mutex_lock(&d->print_lock);
			printf("%lld %d died\n",
				get_time() - d->start_time, d->philos[i].id);
			pthread_mutex_unlock(&d->print_lock);
			return (1);
		}
		pthread_mutex_unlock(&d->state_lock);
		i++;
	}
	return (0);
}

static int	check_all_ate(t_data *d)
{
	int	i;
	int	count;

	if (d->must_eat < 0)
		return (0);
	i = 0;
	count = 0;
	while (i < d->number_of_philosophers)
	{
		if (d->philos[i].meals_eaten >= d->must_eat)
			count++;
		i++;
	}
	return (count == d->number_of_philosophers);
}

int	monitor_simulation(t_data *data)
{
	while (1)
	{
		usleep(100);
		if (check_death(data))
			break ;
		if (check_all_ate(data))
		{
			pthread_mutex_lock(&data->print_lock);
			printf("Everyone ate %d times\n", data->must_eat);
			pthread_mutex_unlock(&data->print_lock);
			pthread_mutex_lock(&data->state_lock);
			data->simulation_over = 1;
			pthread_mutex_unlock(&data->state_lock);
			break ;
		}
	}
	return (0);
}

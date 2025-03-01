/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
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

int	check_sim(t_data *d)
{
	int	ret;

	pthread_mutex_lock(&d->state_lock);
	ret = d->simulation_over;
	pthread_mutex_unlock(&d->state_lock);
	return (ret);
}

static int	create_threads(t_data *d)
{
	int	i;

	d->start_time = get_time();
	i = 0;
	while (i < d->number_of_philosophers)
	{
		d->philos[i].last_meal = d->start_time;
		if (pthread_create(&d->philos[i].thread_id, NULL,
				philo_routine, &d->philos[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

static int	join_threads(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->number_of_philosophers)
	{
		pthread_join(d->philos[i].thread_id, NULL);
		i++;
	}
	return (0);
}

int	start_simulation(t_data *data)
{
	if (create_threads(data))
		return (1);
	if (monitor_simulation(data))
		return (1);
	if (join_threads(data))
		return (1);
	return (0);
}

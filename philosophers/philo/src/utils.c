/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+        */
/*   Created: 2025/02/19 17:07:31 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/19 17:07:32 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

long long	get_time(void)
{
	struct timeval	tv;
	long long		ms;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (ms);
}

void	ft_usleep(long long time_in_ms, t_data *data)
{
	long long	start;

	start = get_time();
	while ((get_time() - start) < time_in_ms)
	{
		pthread_mutex_lock(&data->state_lock);
		if (data->simulation_over)
		{
			pthread_mutex_unlock(&data->state_lock);
			break ;
		}
		pthread_mutex_unlock(&data->state_lock);
		usleep(50);
	}
}

void	safe_print(t_data *d, int id, char *msg)
{
	long long	t;
	int			sim_over;

	pthread_mutex_lock(&d->print_lock);
	pthread_mutex_lock(&d->state_lock);
	sim_over = d->simulation_over;
	pthread_mutex_unlock(&d->state_lock);
	if (sim_over && strcmp(msg, "died") != 0)
	{
		pthread_mutex_unlock(&d->print_lock);
		return ;
	}
	t = get_time() - d->start_time;
	printf("%lld %d %s\n", t, id, msg);
	pthread_mutex_unlock(&d->print_lock);
}

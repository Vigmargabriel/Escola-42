/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:06:47 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/19 17:06:50 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "philo.h"

static int	parse_args(int ac, char **av, t_data *data)
{
	int	tmp;

	if (ac < 5 || ac > 6)
		return (1);
	data->number_of_philosophers = atoi(av[1]);
	data->time_to_die = atoi(av[2]);
	data->time_to_eat = atoi(av[3]);
	data->time_to_sleep = atoi(av[4]);
	data->must_eat = -1;
	if (ac == 6)
	{
		tmp = atoi(av[5]);
		if (tmp < 1)
			return (1);
		data->must_eat = tmp;
	}
	if (data->number_of_philosophers < 1 || data->time_to_die < 1
		|| data->time_to_eat < 1 || data->time_to_sleep < 1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (parse_args(ac, av, &data))
	{
		printf("Error in arguments\\n");
		return (1);
	}
	if (init_all(&data))
		return (1);
	start_simulation(&data);
	cleanup(&data);
	return (0);
}

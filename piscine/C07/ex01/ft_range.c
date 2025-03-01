/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:42:29 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/29 14:42:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	size;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	range = (int *)malloc(size * sizeof(int));
	if (range == NULL)
		return (NULL);
	i = 0;
	while (min < max)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (range);
}
/*
#include <stdio.h> // para printf

int	*ft_range(int min, int max);

int	main(void)
{
	int	min = 50;
	int	max = 20;
	int	*range;
	int	i;

	range = ft_range(min, max);
	if (range != NULL)
	{
		for (i = 0; i < max - min; i++)
			printf("%d ", range[i]);
		free(range);
	}
	else
	{
		printf("Erro: min é maior ou igual a max.\n");
	}
	return (0);
}*/

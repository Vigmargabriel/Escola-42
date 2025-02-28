/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:32:42 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/14 18:32:43 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ctype.h>

int	is_number(const char *str)
{
	if (!str || *str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	rotate_to_position(t_stack **stack, int size, int position)
{
	if (position <= size / 2)
	{
		while (position--)
			ra(stack);
	}
	else
	{
		position = size - position;
		while (position--)
			rra(stack);
	}
}

int	is_order(t_stack **stack, int size)
{
	int		position;
	t_stack	*tmp;

	position = 0;
	tmp = *stack;
	while (tmp && tmp->index != 0)
	{
		position++;
		tmp = tmp->next;
	}
	if (is_sorted(stack) == 1)
	{
		rotate_to_position(stack, size, position);
		return (1);
	}
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:15:43 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/14 20:15:48 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_all_elements_by_content(t_stack **stack)
{
	int		index;
	t_stack	*current;
	t_stack	*min_node;

	index = 0;
	while (1)
	{
		current = *stack;
		min_node = NULL;
		while (current)
		{
			if (current->index == -1
				&& (!min_node || current->content < min_node->content))
				min_node = current;
			current = current->next;
		}
		if (!min_node)
			break ;
		min_node->index = index++;
	}
}

int	is_sorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current && current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	reset_index(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current)
	{
		current->index = -1;
		current = current->next;
	}
	index_all_elements_by_content(stack);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:14:30 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/14 20:14:39 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lst_new(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	lst_addback(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = lst_last(*stack);
	last->next = new;
	new->prev = last;
}

void	lst_addfront(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

t_stack	*lst_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

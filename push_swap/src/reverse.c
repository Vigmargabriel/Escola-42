/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:59:35 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/14 17:59:37 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * reverse - Rotates all elements of a stack downwards.
 * @stack: Pointer to the stack to be rotated.
 * 
 * The last element becomes the first.
 */
static void	reverse(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = lst_last(*stack);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

/**
 * rra - Rotates stack a downwards and prints "rra".
 * @stack: Pointer to stack a.
 */
void	rra(t_stack **stack)
{
	reverse(stack);
	ft_putstr_fd("rra\n", 1);
}

/**
 * rrb - Rotates stack b downwards and prints "rrb".
 * @stack: Pointer to stack b.
 */
void	rrb(t_stack **stack)
{
	reverse(stack);
	ft_putstr_fd("rrb\n", 1);
}

/**
 * rrr - Rotates both stacks a and b downwards and prints "rrr".
 * @a_stack: Pointer to stack a.
 * @b_stack: Pointer to stack b.
 */
void	rrr(t_stack **a_stack, t_stack **b_stack)
{
	reverse(a_stack);
	reverse(b_stack);
	ft_putstr_fd("rrr\n", 1);
}

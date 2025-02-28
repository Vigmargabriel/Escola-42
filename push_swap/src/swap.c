/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:52:56 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/14 17:52:57 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * swap - Swaps the first two elements of a stack.
 * @stack: Pointer to the stack.
 * 
 * If the stack has less than two elements, the function does nothing.
 */
static void	swap(t_stack **stack)
{
	int	temp_content;
	int	temp_index;

	if (!(*stack) || !(*stack)->next)
		return ;
	temp_content = (*stack)->content;
	temp_index = (*stack)->index;
	(*stack)->content = (*stack)->next->content;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->content = temp_content;
	(*stack)->next->index = temp_index;
}

/**
 * sa - Swaps the first two elements of stack a and prints "sa".
 * @stack: Pointer to stack a.
 */
void	sa(t_stack **stack)
{
	swap(stack);
	ft_putstr_fd("sa\n", 1);
}

/**
 * sb - Swaps the first two elements of stack b and prints "sb".
 * @stack: Pointer to stack b.
 */
void	sb(t_stack **stack)
{
	swap(stack);
	ft_putstr_fd("sb\n", 1);
}

/**
 * ss - Swaps the first two elements of both stacks a and b and prints "ss".
 * @a_stack: Pointer to stack a.
 * @b_stack: Pointer to stack b.
 */
void	ss(t_stack **a_stack, t_stack **b_stack)
{
	swap(a_stack);
	swap(b_stack);
	ft_putstr_fd("ss\n", 1);
}

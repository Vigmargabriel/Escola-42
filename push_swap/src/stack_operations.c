/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:00:35 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/14 18:00:37 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_elements(t_stack **stack)
{
	if ((*stack)->content > (*stack)->next->content)
		sa(stack);
}

/**
 * sort_three_elements - Sorts a stack with exactly three elements.
 * @stack: Pointer to the stack to be sorted.
 * 
 * Uses minimal operations to sort three elements.
 */
static void	sort_three_elements(t_stack **stack)
{
	while (is_sorted(stack) != 1)
	{
		if (((*stack)->index > (*stack)->next->index)
			&& ((*stack)->index < (*stack)->next->next->index))
			sa(stack);
		else if (((*stack)->index > (*stack)->next->index)
			&& ((*stack)->index > (*stack)->next->next->index))
			ra(stack);
		else
			rra(stack);
	}
}

/**
 * sort_four_elements - Sorts a stack with exactly 
 four elements using an auxiliary stack.
 * @a_stack: Pointer to stack a.
 * @b_stack: Pointer to stack b.
 */
static void	sort_four_elements(t_stack **a_stack, t_stack **b_stack)
{
	if (is_order(a_stack, 4) == 1)
		return ;
	rotate_to_min(a_stack, 4);
	pb(a_stack, b_stack);
	reset_index(a_stack);
	sort_three_elements(a_stack);
	pa(a_stack, b_stack);
}

/**
 * sort_five_elements - Sorts a stack with exactly 
 five elements using an auxiliary stack.
 * @a_stack: Pointer to stack a.
 * @b_stack: Pointer to stack b.
 */
static void	sort_five_elements(t_stack **a_stack, t_stack **b_stack)
{
	if (is_order(a_stack, 5) == 1)
		return ;
	rotate_to_min(a_stack, 5);
	pb(a_stack, b_stack);
	reset_index(a_stack);
	sort_four_elements(a_stack, b_stack);
	pa(a_stack, b_stack);
}

/**
 * conditional_sort_based_on_size - Sorts stacks with size <= 5.
 * @a_stack: Pointer to stack a.
 * @b_stack: Pointer to stack b.
 */
void	conditional_sort_based_on_size(t_stack **a_stack, t_stack **b_stack)
{
	int	size;

	size = get_stack_size(*a_stack);
	if (size == 2)
		sort_two_elements(a_stack);
	else if (size == 3)
		sort_three_elements(a_stack);
	else if (size == 4)
		sort_four_elements(a_stack, b_stack);
	else if (size == 5)
		sort_five_elements(a_stack, b_stack);
}

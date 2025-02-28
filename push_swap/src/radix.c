/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:01:37 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/14 18:01:39 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * calculate_max_index_bits - Calculates the maximum 
 number of bits needed to represent
 * all indices in the stack.
 * @stack: Pointer to the stack.
 * 
 * Returns the maximum number of bits required.
 */
static int	calculate_max_index_bits(t_stack **stack)
{
	t_stack	*current;
	int		max;
	int		max_bits;

	current = *stack;
	max = current->index;
	max_bits = 0;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **a_stack, t_stack **b_stack)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

	size = get_stack_size(*a_stack);
	max_bits = calculate_max_index_bits(a_stack);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a_stack)->index >> i) & 1) == 0)
				pb(a_stack, b_stack);
			else
				ra(a_stack);
			j++;
		}
		while (get_stack_size(*b_stack) > 0)
			pa(a_stack, b_stack);
		i++;
	}
}
/**
 * radix_sort - Sorts a stack using the radix sort algorithm.
 * @a_stack: Pointer to stack a.
 * @b_stack: Pointer to stack b.
 */

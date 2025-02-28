/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:02:41 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/14 18:02:43 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * main - Entry point for the push_swap program.
 * @ac: Argument count.
 * @av: Argument vector.
 * 
 * Returns 0 on successful execution.
 */
int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	if (ac < 2)
		return (0);
	a_stack = NULL;
	b_stack = NULL;
	if (!ps_initstack(ac, av, &a_stack) || ps_check_dup(a_stack) == -1)
		print_error_and_exit(&a_stack);
	index_all_elements_by_content(&a_stack);
	if (is_sorted(&a_stack) == 1)
	{
		ps_stackclear(&a_stack);
		return (0);
	}
	if (get_stack_size(a_stack) <= 5)
		conditional_sort_based_on_size(&a_stack, &b_stack);
	else
		radix_sort(&a_stack, &b_stack);
	ps_stackclear(&a_stack);
	ps_stackclear(&b_stack);
	return (0);
}
/*
// Initialize stack a with the input values
	if (!ps_initstack(ac, av, &a_stack) || ps_check_dup(a_stack) == -1)
		print_error_and_exit(&a_stack);
	// Assign indices to all elements for sorting
	index_all_elements_by_content(&a_stack);
	// If the stack is already sorted, clean up and exit
	if (is_sorted(&a_stack) == 1)
	{
		ps_stackclear(&a_stack);
		return (0);
	}
	// Choose sorting algorithm based on stack size
	if (get_stack_size(a_stack) <= 5)
		conditional_sort_based_on_size(&a_stack, &b_stack);
	else
		radix_sort(&a_stack, &b_stack);
	// Clean up
	ps_stackclear(&a_stack);
	ps_stackclear(&b_stack);
	return (0);
*/

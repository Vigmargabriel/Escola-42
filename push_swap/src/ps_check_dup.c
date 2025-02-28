/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:50:41 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/14 17:50:44 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * ps_check_dup - Checks for duplicate values in the stack.
 * @stack: Pointer to the stack to be checked.
 * 
 * Returns -1 if a duplicate is found, 1 otherwise.
 */
int	ps_check_dup(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;

	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->content == runner->content)
				return (-1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:56:18 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/14 17:56:19 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * push - Pushes the top element of one stack onto another.
 * @dest_stack: Pointer to the stack where the element will be pushed.
 * @src_stack: Pointer to the stack from where the element will be taken.
 * 
 * If the source stack is empty, the function does nothing.
 */
static void	push(t_stack **dest_stack, t_stack **src_stack)
{
	t_stack	*tmp;

	if (!src_stack || !(*src_stack))
		return ;
	tmp = (*src_stack)->next;
	lst_addfront(dest_stack, *src_stack);
	*src_stack = tmp;
	if (*src_stack)
		(*src_stack)->prev = NULL;
}

/**
 * pa - Pushes the top element of stack b onto stack a and prints "pa".
 * @a_stack: Pointer to stack a.
 * @b_stack: Pointer to stack b.
 */
void	pa(t_stack **a_stack, t_stack **b_stack)
{
	push(a_stack, b_stack);
	ft_putstr_fd("pa\n", 1);
}

/**
 * pb - Pushes the top element of stack a onto stack b and prints "pb".
 * @a_stack: Pointer to stack a.
 * @b_stack: Pointer to stack b.
 */
void	pb(t_stack **a_stack, t_stack **b_stack)
{
	push(b_stack, a_stack);
	ft_putstr_fd("pb\n", 1);
}

void	ra(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = lst_last(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	ft_putstr_fd("ra\n", 1);
}

void	rotate_to_min(t_stack **stack, int size)
{
	t_stack	*current;
	int		position;

	current = *stack;
	position = 0;
	while (current)
	{
		if (current->index == 0)
			break ;
		current = current->next;
		position++;
	}
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

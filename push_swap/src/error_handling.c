/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:51:59 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/14 17:52:01 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * print_error_and_exit - Prints "Error" and exits the program.
 * @a_stack: Pointer to the stack to be cleared before exiting.
 * 
 * Frees all allocated memory and exits with a failure status.
 */
void	print_error_and_exit(t_stack **a_stack)
{
	ft_putstr_fd("Error\n", 2);
	ps_stackclear(a_stack);
	exit(1);
}

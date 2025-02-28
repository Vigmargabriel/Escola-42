/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_initstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:57:12 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/14 15:57:14 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * validate_and_add_to_stack - Validates input and adds numbers to stack.
 * @split: Array of strings split from arguments.
 * @a_stack: Pointer to the stack being initialized.
 * 
 * Returns 1 if successful, exits with an error message otherwise.
 */
int	validate_and_add_to_stack(char **split, t_stack **a_stack)
{
	long	num;
	int		i;

	i = 0;
	while (split[i])
	{
		if (!is_number(split[i]) || ft_strlen(split[i]) == 0)
		{
			free_split(split);
			ps_stackclear(a_stack);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		num = ft_atoi(split[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free_split(split);
			ps_stackclear(a_stack);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		lst_addback(a_stack, lst_new(ft_atoi(split[i])));
		i++;
	}
	return (1);
}

/**
 * ps_initstack - Initializes stack a from program arguments.
 * @ac: Argument count.
 * @av: Argument vector.
 * @a_stack: Pointer to stack a.
 * 
 * Returns 1 if successful, exits with an error message otherwise.
 */
int	ps_initstack(int ac, char **av, t_stack **a_stack)
{
	char	**split;
	int		i;

	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split || !validate_and_add_to_stack(split, a_stack))
		{
			free_split(split);
			ps_stackclear(a_stack);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		free_split(split);
		i++;
	}
	return (1);
}

void	ps_stackclear(t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	ps_stackclear(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}

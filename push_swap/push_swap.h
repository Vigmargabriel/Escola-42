/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:05:01 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/02/14 18:05:04 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_personal/libft_personal.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/**
 * Struct representing a stack node.
 */
typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// Initialization and error handling
int					ps_initstack(int ac, char **av, t_stack **a_stack);
int					validate_and_add_to_stack(char **split, t_stack **a_stack);
void				print_error_and_exit(t_stack **a_stack);
int					ps_check_dup(t_stack *stack);

// Stack operations
void				sa(t_stack **stack);
void				sb(t_stack **stack);
void				ss(t_stack **a_stack, t_stack **b_stack);
void				pa(t_stack **a_stack, t_stack **b_stack);
void				pb(t_stack **a_stack, t_stack **b_stack);
void				ra(t_stack **stack);
void				rb(t_stack **stack);
void				rr(t_stack **a_stack, t_stack **b_stack);
void				rra(t_stack **stack);
void				rrb(t_stack **stack);
void				rrr(t_stack **a_stack, t_stack **b_stack);

// Sorting algorithms
void				conditional_sort_based_on_size(t_stack **a_stack,
						t_stack **b_stack);
void				radix_sort(t_stack **a_stack, t_stack **b_stack);

// Stack utilities
int					get_stack_size(t_stack *stack);
int					is_sorted(t_stack **stack);
void				index_all_elements_by_content(t_stack **stack);
void				ps_stackclear(t_stack **stack);
void				reset_index(t_stack **stack);
void				rotate_to_min(t_stack **stack, int size);

// Libft-like helper functions
size_t				ft_strlen(const char *s);
// void	ft_putstr_fd(const char *s, int fd);
// char    **ft_split(const char *s, char c);
void				free_split(char **split);
t_stack				*lst_new(int content);
void				lst_addfront(t_stack **stack, t_stack *new);
void				lst_addback(t_stack **stack, t_stack *new);
t_stack				*lst_last(t_stack *stack);

// adicionados por ultimo
int					is_number(const char *str);
int				ft_atoi(const char *str);
void				sort_two_elements(t_stack **stack);
int					is_order(t_stack **stack, int size);
void				rotate_to_position(t_stack **stack, int size, int position);
void				ps_stackclear(t_stack **stack);
void				free_split(char **split);
// char **ft_split(const char *s, char c);
void				index_all_elements_by_content(t_stack **stack);
int					is_sorted(t_stack **stack);
int					get_stack_size(t_stack *stack);
void				ra(t_stack **stack);
void				rotate_to_min(t_stack **stack, int size);

// funçao para  liberar as pilhas/stack
void				free_stack(t_stack **stack);

#endif

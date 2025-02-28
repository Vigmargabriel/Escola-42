/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:51:38 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/29 12:51:44 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
#define SQUARE_H

#include <stddef.h>

void find_biggest_square(char **map, int rows, size_t cols, char obstacle, int *max_size, int *max_row, int *max_col);
void mark_biggest_square(char **map, int max_size, int max_row, int max_col, char full);

#endif

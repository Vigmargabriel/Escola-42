/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:51:23 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/29 12:51:28 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "square.h"

int min(int a, int b, int c) {
    int min = a < b ? a : b;
    return min < c ? min : c;
}

void find_biggest_square(char **map, int rows, size_t cols, char obstacle, int *max_size, int *max_row, int *max_col) {
    int **dp = malloc(rows * sizeof(int *));
    int i = 0;

    while (i < rows) {
        dp[i] = malloc(cols * sizeof(int));
        i++;
    }

    *max_size = 0;
    *max_row = 0;
    *max_col = 0;

    i = 0;
    while (i < rows) {
        size_t j = 0; // Usar size_t para j
        while (j < cols) {
            if (map[i][j] == obstacle) {
                dp[i][j] = 0;
            } else if (i == 0 || j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
            }

            if (dp[i][j] > *max_size) {
                *max_size = dp[i][j];
                *max_row = i;
                *max_col = j;
            }
            j++;
        }
        i++;
    }

    i = 0;
    while (i < rows) {
        free(dp[i]);
        i++;
    }
    free(dp);
}

void mark_biggest_square(char **map, int max_size, int max_row, int max_col, char full) {
    int i = max_row;
    while (i > max_row - max_size) {
        int j = max_col;
        while (j > max_col - max_size) {
            map[i][j] = full;
            j--;
        }
        i--;
    }
}

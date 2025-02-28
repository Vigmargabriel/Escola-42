/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:57:43 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/29 11:57:59 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "square.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
        return 1;
    }

    int i = 1;
    while (i < argc) {
        int rows;
        size_t cols;
        char empty, obstacle, full;
        char **map = read_map(argv[i], &rows, &cols, &empty, &obstacle, &full);
        if (!map) {
            fprintf(stderr, "map error\n");
            i++;
            continue;
        }

        printf("Map read successfully: %s\n", argv[i]); // Depuração
        printf("Rows: %d, Cols: %zu, Empty: '%c', Obstacle: '%c', Full: '%c'\n", rows, cols, empty, obstacle, full); // Depuração

        int max_size, max_row, max_col;
        find_biggest_square(map, rows, cols, obstacle, &max_size, &max_row, &max_col);
        printf("Biggest square found at row %d, col %d, size %d\n", max_row, max_col, max_size); // Depuração

        mark_biggest_square(map, max_size, max_row, max_col, full);
        print_map(map, rows);
        if (i < argc - 1) {
            printf("\n");
        }
        i++;
    }

    return 0;
}

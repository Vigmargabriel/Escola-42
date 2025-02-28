/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:50:59 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/29 12:51:04 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

char **read_map(const char *filename, int *rows, size_t *cols, char *empty, char *obstacle, char *full) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    // Debug: Print the filename being read
    printf("Reading file: %s\n", filename);

    // Read the first line containing the map info
    if (fscanf(file, "%d%c%c%c\n", rows, empty, obstacle, full) != 4) {
        fprintf(stderr, "Error reading map info\n");
        fclose(file);
        return NULL;
    }

    // Debug: Print the map info
    printf("Rows: %d, Empty: '%c', Obstacle: '%c', Full: '%c'\n", *rows, *empty, *obstacle, *full);

    char **map = malloc(*rows * sizeof(char *));
    if (!map) {
        perror("Memory allocation error");
        fclose(file);
        return NULL;
    }

    char line[1024];
    *cols = 0;
    int i = 0;
    while (i < *rows) {
        if (fgets(line, sizeof(line), file)) {
            line[strcspn(line, "\n")] = '\0';  // Remove newline character
            if (i == 0) {
                *cols = strlen(line);
            } else if (strlen(line) != *cols) {
                fprintf(stderr, "Map error: lines of different lengths\n");
                free(map);
                fclose(file);
                return NULL;
            }
            map[i] = strdup(line);
            if (!map[i]) {
                perror("Memory allocation error");
                free(map);
                fclose(file);
                return NULL;
            }
            // Debug: Print each line of the map
            printf("Line %d: %s\n", i, line);
        } else {
            fprintf(stderr, "Map error: not enough lines\n");
            free(map);
            fclose(file);
            return NULL;
        }
        i++;
    }

    fclose(file);
    return map;
}

void print_map(char **map, int rows) {
    int i = 0;
    while (i < rows) {
        printf("%s\n", map[i]);
        free(map[i]);
        i++;
    }
    free(map);
}

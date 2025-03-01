/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:50:33 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/29 12:50:44 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include <stddef.h>

char **read_map(const char *filename, int *rows, size_t *cols, char *empty, char *obstacle, char *full);
void print_map(char **map, int rows);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:50:34 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/27 15:50:39 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

typedef struct s_dict {
    unsigned long long number;
    char *word;
    struct s_dict *next;
} t_dict;

t_dict *parse_dict(char *filename);
void free_dict(t_dict *dict);

#endif

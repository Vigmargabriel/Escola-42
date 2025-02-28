/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:51:01 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/27 15:51:11 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dict.h"
#include "utils.h"

t_dict *create_dict_entry(unsigned long long number, char *word)
{
    t_dict *entry;

    entry = malloc(sizeof(t_dict));
    if (!entry)
        return (NULL);
    entry->number = number;
    entry->word = ft_strdup(word);
    entry->next = NULL;
    return (entry);
}

void free_dict(t_dict *dict)
{
    t_dict *tmp;

    while (dict)
    {
        tmp = dict;
        dict = dict->next;
        free(tmp->word);
        free(tmp);
    }
}

t_dict *parse_dict(char *filename)
{
    FILE *file;
    t_dict *dict;
    t_dict *tail;
    char *line;
    size_t len;
    unsigned long long number;
    char *word;

    file = fopen(filename, "r");
    if (!file)
        return (NULL);
    dict = NULL;
    line = NULL;
    len = 0;
    while (getline(&line, &len, file) != -1)
    {
        if (parse_line(line, &number, &word))
        {
            t_dict *entry = create_dict_entry(number, word);
            if (!entry)
                return (free(line), fclose(file), free_dict(dict), NULL);
            if (!dict)
                dict = entry;
            else
                tail->next = entry;
            tail = entry;
        }
    }
    free(line);
    fclose(file);
    return (dict);
}

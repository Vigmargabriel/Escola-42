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
#include <unistd.h>
#include <fcntl.h>
#include "dict.h"
#include "utils.h"

t_dict *create_dict_entry(unsigned long long number, char *word)
{
    t_dict *entry;

    entry = (t_dict *)malloc(sizeof(t_dict));
    if (!entry)
        return NULL;
    entry->number = number;
    entry->word = word;
    entry->next = NULL;
    return entry;
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
    int fd;
    int ret;
    char buf[4096];
    char *line;
    char *word;
    unsigned long long number;
    t_dict *dict = NULL;
    t_dict *tail = NULL;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return NULL;
    ret = read(fd, buf, 4096);
    if (ret < 0)
        return NULL;
    buf[ret] = '\0';
    line = strtok(buf, "\n");
    while (line)
    {
        if (parse_line(line, &number, &word))
        {
            t_dict *entry = create_dict_entry(number, word);
            if (!entry)
                return free_dict(dict), NULL;
            if (!dict)
                dict = entry;
            else
                tail->next = entry;
            tail = entry;
        }
        line = strtok(NULL, "\n");
    }
    close(fd);
    return dict;
}

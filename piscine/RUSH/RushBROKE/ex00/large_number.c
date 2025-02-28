/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:21:02 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/27 17:21:14 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "large_number.h"
#include "utils.h"

char *find_dict_entry(t_dict *dict, unsigned long long number)
{
    t_dict *entry = dict;
    while (entry)
    {
        if (entry->number == number)
            return entry->word;
        entry = entry->next;
    }
    return NULL;
}

void print_chunk(unsigned long long number, t_dict *dict)
{
    char *word;

    if (number >= 100)
    {
        word = find_dict_entry(dict, number / 100);
        if (word)
        {
            write(1, word, ft_strlen(word));
            write(1, " hundred", 8);
            number %= 100;
            if (number > 0)
                write(1, " ", 1);
        }
    }
    if (number >= 20)
    {
        word = find_dict_entry(dict, (number / 10) * 10);
        if (word)
        {
            write(1, word, ft_strlen(word));
            number %= 10;
            if (number > 0)
                write(1, " ", 1);
        }
    }
    if (number > 0)
    {
        word = find_dict_entry(dict, number);
        if (word)
            write(1, word, ft_strlen(word));
    }
}

void print_large_number(char *number_str, t_dict *dict)
{
    char *units[] = {
        "undecillion",
        "decillion",
        "nonillion",
        "octillion",
        "septillion",
        "sextillion",
        "quintillion",
        "quadrillion",
        "trillion",
        "billion",
        "million",
        "thousand",
        ""
    };
    int unit_index = 0;
    int len = strlen(number_str);
    int chunk_size;
    char chunk[4];

    while (len > 0)
    {
        chunk_size = len % 3 == 0 ? 3 : len % 3;
        strncpy(chunk, number_str, chunk_size);
        chunk[chunk_size] = '\0';

        unsigned long long part = strtoull(chunk, NULL, 10);
        if (part > 0)
        {
            print_chunk(part, dict);
            if (units[unit_index][0] != '\0')
            {
                write(1, " ", 1);
                write(1, units[unit_index], ft_strlen(units[unit_index]));
                write(1, " ", 1);
            }
        }

        number_str += chunk_size;
        len -= chunk_size;
        unit_index++;
    }
}

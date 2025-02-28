/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:51:50 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/27 15:51:57 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "convert.h"
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

int convert_number_to_words(char *number_str, t_dict *dict)
{
    unsigned long long number;
    unsigned long long divisors[] = {
        1000000000000000000000000000000000ULL,  // undecillion
        1000000000000000000000000000000ULL,    // decillion
        1000000000000000000000000000ULL,       // nonillion
        1000000000000000000000000ULL,          // octillion
        1000000000000000000000ULL,             // septillion
        1000000000000000000ULL,                // sextillion
        1000000000000000ULL,                   // quintillion
        1000000000000ULL,                      // quadrillion
        1000000000ULL,                         // billion
        1000000ULL,                            // million
        1000ULL,                               // thousand
        1ULL                                   // unit
    };
    char *units[] = {
        " undecillion", " decillion", " nonillion", " octillion", " septillion",
        " sextillion", " quintillion", " quadrillion", " trillion", " billion", 
        " million", " thousand", ""
    };
    int i;
    number = strtoull(number_str, NULL, 10);
    if (number == 0)
    {
        write(1, "zero", 4);
    }
    else
    {
        for (i = 0; i < 12; i++)
        {
            if (number / divisors[i] > 0)
            {
                print_chunk(number / divisors[i], dict);
                if (units[i][0] != '\0')
                    write(1, units[i], ft_strlen(units[i]));
                number %= divisors[i];
                if (number > 0)
                    write(1, " ", 1);
            }
        }
    }
    write(1, "\n", 1);
    return 1;
}

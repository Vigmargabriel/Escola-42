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
#include <unistd.h>
#include "convert.h"
#include "utils.h"
#include "large_number.h"

int convert_number_to_words(char *number_str, t_dict *dict)
{
    unsigned long long number;

    number = strtoull(number_str, NULL, 10);
    if (number == 0)
    {
        write(1, "zero", 4);
    }
    else
    {
        print_large_number(number_str, dict);
    }
    write(1, "\n", 1);
    return 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:49:49 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/27 15:49:56 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "dict.h"
#include "utils.h"
#include "convert.h"

void print_error(char *message)
{
    write(1, message, ft_strlen(message));
}

int main(int argc, char **argv)
{
    char *dict_file;
    char *number;
    t_dict *dict;

    if (argc == 2)
    {
        number = argv[1];
        dict_file = "numbers.dict";
    }
    else if (argc == 3)
    {
        dict_file = argv[1];
        number = argv[2];
    }
    else
    {
        print_error("Error\n");
        return 1;
    }
    if (!is_valid_number(number))
    {
        print_error("Error\n");
        return 1;
    }
    dict = parse_dict(dict_file);
    if (!dict)
    {
        print_error("Dict Error\n");
        return 1;
    }
    if (!convert_number_to_words(number, dict))
    {
        print_error("Dict Error\n");
        return 1;
    }
    free_dict(dict);
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:06:42 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/25 15:06:44 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	comp;

	comp = 0;
	while (str[comp] != '\0')
	{
		comp++;
	}
	return (comp);
}
/*
int main(void)
{
    char *s = "42Luxemburgo! Pool!";
    size_t length;

    // Chamada da função ft_strlen para obter o comprimento da string
    length = ft_strlen(s);

    // Impressão do comprimento da string
    printf("O comprimento da string \"%s\" is %zu.\n", s, length);

    return 0;
}*/
/*
#include <stdio.h>

// Prototipo da função
int ft_strlen(char *str);

int main(void)
{
    char str[] = "42Luxemburgo! Pool!";
    int length;

    // Chamada da função ft_strlen para obter o comprimento da string
    length = ft_strlen(str);

    // Impressão do comprimento da string usando %d
    printf("The length of the string \"%s\" is %d.\n", str, length);

    return 0;
}*/

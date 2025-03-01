/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:32:37 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/23 13:51:08 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	z;

	z = 0;
	while (str[z] != '\0')
	{
		if (str[z] < 32 || str[z] > 126)
		{
			return (0);
		}
		z++;
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	char test1[] = ".,aq12";
	char test2[] = "èüàä";
	char test3[] = "";

	printf("%d\n", ft_str_is_printable(test1)); // Deve imprimir 1
  	printf("%d\n", ft_str_is_printable(test2)); // Deve imprimir 0
    	printf("%d\n", ft_str_is_printable(test3)); // Deve imprimir 1,

    return (0);
}*/

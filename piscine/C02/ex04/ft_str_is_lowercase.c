/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:31:51 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/23 12:05:38 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	v;

	v = 0;
	while (str[v] != '\0')
	{
		if (str[v] < 'a' || str[v] > 'z')
			return (0);
		v++;
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	char test1[] = "adsfags";
	char test2[] = "ASDFG";
	char test3[] = "";

	printf("%d\n", ft_str_is_lowercase(test1)); // Deve imprimir 1
  	printf("%d\n", ft_str_is_lowercase(test2)); // Deve imprimir 0
    	printf("%d\n", ft_str_is_lowercase(test3)); // Deve imprimir 1,

    return (0);
}*/

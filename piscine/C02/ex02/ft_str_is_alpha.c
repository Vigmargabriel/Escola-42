/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:49:05 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/23 10:01:48 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int main(void)
{
	char test1[] = "ABCabc";
	char test2[] = "abcAbC1";
	char test3[] = "";

	printf("%d\n", ft_str_is_alpha(test1)); // Deve imprimir 1
  	printf("%d\n", ft_str_is_alpha(test2)); // Deve imprimir 0
    	printf("%d\n", ft_str_is_alpha(test3)); // Deve imprimir 1,

    return (0);
}*/

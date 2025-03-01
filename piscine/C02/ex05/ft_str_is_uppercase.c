/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:07:03 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/23 12:25:47 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	g;

	g = 0;
	while (str[g] != '\0')
	{
		if (str[g] < 65 || str[g] > 90)
			return (0);
		g++;
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	char	exemplo1[] = "ABFHG";
	char	exemplo2[] = "A 1a A";
	char	exemplo3[] = "";

	printf("%d\n", ft_str_is_uppercase(exemplo1)); // Deve imprimir 1
  	printf("%d\n", ft_str_is_uppercase(exemplo2)); // Deve imprimir 0
    	printf("%d\n", ft_str_is_uppercase(exemplo3)); // Deve imprimir 1,

    return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:44:55 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/23 10:44:59 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	t;

	t = 0;
	while (str[t] != '\0')
	{
		if (str[t] < '0' || str[t] > '9')
		{
			return (0);
		}
		t++;
	}
	return (1);
}
/*
int	main(void)
{
	char test1[] = "123";
	char test2[] = "abvDC";
	char test3[] = "";

	printf("%d\n", ft_str_is_numeric(test1)); // Deve imprimir 1
  	printf("%d\n", ft_str_is_numeric(test2)); // Deve imprimir 0
    	printf("%d\n", ft_str_is_numeric(test3)); // Deve imprimir 1,

    return (0);
}*/

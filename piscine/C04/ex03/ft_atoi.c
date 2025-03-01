/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:35:59 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/25 19:36:01 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	x;
	int	r;
	int	s;

	r = 0;
	x = 0;
	s = 1;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
		x++;
	while (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			s *= -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		r = (str[x] - 48) + (r * 10);
		x++;
	}
	return (r * s);
}
/*
#include <stdio.h>

int	ft_atoi(char *str);

int	main(void)
{
	char *test1 = " ---+--+1234ab567";
	char *test2 = "   +42";
	char *test3 = "   -42";
	char *test4 = "   12345";
	char *test5 = "   --123";

	printf("%d\n", ft_atoi(test1)); // Esperado: -1234
	printf("%d\n", ft_atoi(test2)); // Esperado: 42
	printf("%d\n", ft_atoi(test3)); // Esperado: -42
	printf("%d\n", ft_atoi(test4)); // Esperado: 12345
	printf("%d\n", ft_atoi(test5)); // Esperado: 123
	return (0);
}*/

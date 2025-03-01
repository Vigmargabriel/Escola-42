/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:54:13 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/27 11:54:44 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = 1;
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("0^0 = %d\n", ft_iterative_power(0, 0)); 
	printf("7^-5 = %d\n", ft_iterative_power(7, -5));
	printf("5^3 = %d\n", ft_iterative_power(5, 3)); 
	printf("2^3 = %d\n", ft_iterative_power(2, 3));
	printf("10^0 = %d\n", ft_iterative_power(10, 0));
	return (0);
}*/

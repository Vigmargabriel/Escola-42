/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:02:57 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/27 12:02:59 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("0^0 = %d\n", ft_recursive_power(0, 0)); 
	printf("7^-5 = %d\n", ft_recursive_power(7, -5));
	printf("5^3 = %d\n", ft_recursive_power(5, 3)); 
	printf("2^3 = %d\n", ft_recursive_power(2, 3));
	printf("10^0 = %d\n", ft_recursive_power(10, 0));
	return (0);
}*/

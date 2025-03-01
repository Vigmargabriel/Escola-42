/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:18:21 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/27 12:18:23 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("Fibonacci is 5 %d\n", ft_fibonacci(5));
	printf("Fibonacci is 7 %d\n", ft_fibonacci(7));
	printf("Fibonacci is -5 %d\n", ft_fibonacci(-5));
	printf("Fibonacci is 0 %d\n", ft_fibonacci(0));
	
	return (0);
}*/

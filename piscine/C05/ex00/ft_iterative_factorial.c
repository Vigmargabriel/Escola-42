/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 07:38:44 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/27 10:49:46 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	n;

	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	i = 1;
	n = nb;
	while (i != nb)
	{
		n *= (nb - i);
		i++;
	}
	return (n);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("ft: %d", ft_iterative_factorial(3));
	return (0);
}
*/

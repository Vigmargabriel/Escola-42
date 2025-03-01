/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:03:30 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/18 15:04:53 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	type;

	type = *a;
	*a = *b;
	*b = type;
}
/*
int	main(void)
{
	int	a = 21; // Primeiro valor
	int	b = 42; // Segundo valor

	ft_swap(&a, &b); // Troca os valores de a e b

	printf("Valor de a: %d\nValor de b: %d\n", a, b);

	return (0);
}*/

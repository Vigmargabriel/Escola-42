/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:29:43 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/25 07:38:35 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*ptr;

	ptr = dest;
	while (*ptr)
		ptr++;
	while (nb-- && *src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}
/*
int	main(void)
{

	char	destino[50] = "Carro, ";
	char	origem[] = "Carro";
	unsigned int	numbercopy = 3;

	ft_strncat(destino, origem, numbercopy);
	printf("Resultado da String: %s\n", destino);
	return (0);
}*/

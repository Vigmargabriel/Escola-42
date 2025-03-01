/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:00:06 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/29 11:00:08 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*dup;
	int		i;

	len = 0;
	while (src[len] != '\0')
		len++;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}
/*
#include <stdio.h> // para printf

char	*ft_strdup(char *src); // Declaração da função ft_strdup

int	main(void)
{
	char	str[] = "Hello, 42!";
	char	*dup;

	dup = ft_strdup(str);
	if (dup != NULL)
	{
		printf("Original: %s\nDuplicada: %s\n", str, dup);
		free(dup); // Libera a memória alocada para a string duplicada
	}
	else
	{
		printf("Falha ao duplicar a string.\n");
	}
	return (0);
}*/

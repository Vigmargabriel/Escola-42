/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:09:01 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/22 18:44:25 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	src[] = {"cabo caqui se vai embora!"};
	char	dest[] = {"FOCA JOTAS OI TEM TEMPOS!"};

	printf("\nBefore copy: \npl 1: %s\npl 2: %s\n", src, dest);
	ft_strcpy(dest, src);
	printf("\nAfter copy: \npl 1: %s\npl 2: %s\n", src, dest);
	return (0);
}*/

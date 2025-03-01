/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:27:08 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/24 16:45:24 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	k;
	int	z;

	k = 0;
	z = 0;
	while (dest[k] != '\0')
		k++;
	while (src[z] != '\0')
	{
		dest[k] = src[z];
		k++;
		z++;
	}
	dest[k] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	dest[] = "Mexico";
	char	src[] = "Peru";

	ft_strcat(dest, src);
	printf("%s\n", dest);
	return (0);
}*/

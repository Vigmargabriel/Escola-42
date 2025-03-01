/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:59:45 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/25 09:59:49 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	char			*d;
	const char		*s;
	unsigned int	n;
	unsigned int	dlen;
	unsigned int	slen;

	d = dest;
	s = src;
	n = size;
	dlen = 0;
	slen = 0;
	while (n-- != 0 && *d != '\0')
	{
		d++;
		dlen++;
	}
	n = size - dlen;
	while (src[slen] != '\0')
		slen++;
	if (n == 0)
		return (dlen + slen);
	while (*s != '\0' && n-- > 1)
		*d++ = *s++;
	*d = '\0';
	return (dlen + slen);
}
/*
int	main(void)
{
	char dest[20] = "Mexico";
	const char src[] = "Peru!2.0";
	unsigned int size = sizeof(dest);
	unsigned int result;

	result = ft_strlcat(dest, src, size);
	printf("Resulting string: %s\n", dest);
	printf("Total length: %u\n", result);
	return (0);
}*/

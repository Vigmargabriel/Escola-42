/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:58:55 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/29 16:59:00 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char	*str)
{
	int	z;

	z = 0;
	while (str[z] != '\0')
		z++;
	return (z);
}

char	*ft_strcat(char *s1, char *s2)
{
	int	z;
	int	j;

	j = 0;
	z = ft_strlen(s1);
	while (s2[j] != '\0')
	{
		s1[z] = s2[j];
		z++;
		j++;
	}
	s1[z] = '\0';
	return (s1);
}

int	ft_alloc(int size, char **strs, char *sep)
{
	int	z;
	int	str;

	z = 0;
	str = 0;
	while (z < size)
		str += ft_strlen(strs[z++]);
	str += (size - 1) * ft_strlen(sep);
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*strjoin;
	int		sizejoin;
	int		q;

	if (size == 0)
	{
		strjoin = (char *)malloc(1);
		if (strjoin)
			strjoin[0] = '\0';
		return (strjoin);
	}
	sizejoin = ft_alloc(size, strs, sep);
	strjoin = (char *)malloc(sizejoin + 1);
	if (!strjoin)
		return (NULL);
	q = 0;
	strjoin[0] = '\0';
	while (q < size)
	{
		strjoin = ft_strcat(strjoin, strs[q]);
		if (q < size - 1)
			strjoin = ft_strcat(strjoin, sep);
		q++;
	}
	return (strjoin);
}
/*
int	main(void)
{
	char	**strs = (char **)malloc(20);

	strs[0] = "RIO de";
	strs[1] = "Janeiro";
	printf("String Junta: %s\n", ft_strjoin(2, strs, "."));
}*/

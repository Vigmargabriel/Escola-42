/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:58:24 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/23 18:58:30 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
			i++;
	}
	return (s1[i] - s2[i]);
}

int	main(void)
{
	char	*s1 = "Abelha caida";
	char	*s2 = "zorro X";
	
	int cs1 = ft_strcmp(s1, s2);
	printf("%d", cs1);
	return(0);
}
/*int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	if (*s1 < *s2)
		return (-1);
	else if (*s1 > *s2)
		return (1);
	else
		return (0);
}

int	main(void)
{

	char *str1 = "a";
	char *str2 = "v";

	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	printf("strcmp: %d\n", ft_strcmp(str1, str2));

	return (0);
}*/

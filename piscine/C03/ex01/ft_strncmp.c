/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:16:54 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/23 20:16:57 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "EstudAr";
	s2 = "Estudar";
	printf("Str 1: %s\n", s1);
	printf("Str 2: %s\n", s2);
	printf("strncmp: %d\n", ft_strncmp(s1, s2, 6));
	return (0);
}*/
/*int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;	
	if (i == n)
	{
		return (0);
	}
	while (i < n && s1[i] && s1[i] == s2[i])
    {
        i++;
    }

    return (s1[i] - (s2[i]);
}

int main(void)
{
    char s1;
    char s2;
    
    s1 = "Estudar";
    s2 = "Estud@";
    printf("Str 1: %s\n", s1);
    printf("Str 2: %s\n", s2);
    printf("strncmp: %d", ft_strncmp(s1, s2, 6));
    
    return 0;
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:05:31 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/25 09:17:36 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*s1;
	char	*s2;

	if (!*to_find)
		return (str);
	while (*str)
	{
		s1 = str;
		s2 = to_find;
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (!*s2)
			return (str);
		str++;
	}
	return (NULL);
}
/*
int main(void)
{
    char str[] = "Casa do 2Chapeu";
    char to_find[] = "Chapeu";

    char *result = ft_strstr(str, to_find);

    if (result)
        printf("Substring found: %s\n", result);
    else
        printf("Substring not found.\n");

    return 0;
}*/

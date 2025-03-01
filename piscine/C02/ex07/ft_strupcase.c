/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:51:48 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/23 14:22:42 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
    char str1[] = "hello";
    char str2[] = "12345";
    char str3[] = "hEllO";
    char str4[] = "HELLO";
    char str5[] = "como vai";
    char str6[] = "";

    printf("%s\n", ft_strupcase(str1)); // Deve imprimir "HELLO"
    printf("%s\n", ft_strupcase(str2)); // Deve imprimir "12345"
    printf("%s\n", ft_strupcase(str3)); // Deve imprimir "HELLO"
    printf("%s\n", ft_strupcase(str4)); // Deve imprimir "HELLO"
    printf("%s\n", ft_strupcase(str5)); // Deve imprimir "COMO VAI"
    printf("%s\n", ft_strupcase(str6)); // Deve imprimir  nada

    return 0;
}*/

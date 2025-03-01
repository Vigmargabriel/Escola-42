/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:23:48 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/23 14:43:53 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	g;

	g = 0;
	while (str[g] != '\0')
	{
		if (str[g] >= 'A' && str[g] <= 'Z')
		{
			str[g] = str[g] +32;
		}
		g++;
	}
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
    char str1[] = "CASA";
    char str2[] = "12345";
    char str3[] = "InCoNsTiTUCIoNaL";
    char str4[] = "casa";
    char str5[] = "EsCreVER C/ Canet@";
    char str6[] = "";

    printf("%s\n", ft_strlowcase(str1)); // Deve imprimir "casa"
    printf("%s\n", ft_strlowcase(str2)); // Deve imprimir "12345"
    printf("%s\n", ft_strlowcase(str3)); // Deve imprimir "casa"
    printf("%s\n", ft_strlowcase(str4)); // Deve imprimir "casa"
    printf("%s\n", ft_strlowcase(str5)); // Deve imprimir "como vai"
    printf("%s\n", ft_strlowcase(str6)); // Deve imprimir  nada

    return 0;
}*/

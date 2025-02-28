/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:39:32 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/10/21 18:48:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_personal.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
** ft_strlen:
** Retorna o comprimento da string `s`.
*/

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = 0;
	while (s1[len] != '\0')
		len++;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}
/*
** ft_strdup:
** Cria uma cópia da string `s1` alocando nova memória.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*js;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	js = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!js)
		return (NULL);
	i = 0;
	while (*s1)
		js[i++] = *s1++;
	while (*s2)
		js[i++] = *s2++;
	js[i] = '\0';
	return (js);
}
/*
** ft_strjoin:
** Concatena `s1` e `s2` em uma nova string.
**js = join string
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

/*
** ft_strchr:
** Localiza a primeira ocorrência de `c` em `s`.
*/

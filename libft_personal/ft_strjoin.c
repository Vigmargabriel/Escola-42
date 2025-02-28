/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:39:13 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/10/24 12:55:57 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_personal.h"

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
js = joined_str
*/

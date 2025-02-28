/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:52:40 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/27 15:52:46 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// utils.c
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"

int	is_valid_number(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	parse_line(char *line, unsigned long long *number, char **word)
{
	char	*colon;
	char	*start;
	char	*end;

	colon = strchr(line, ':');
	if (!colon)
		return (0);
	*colon = '\0';
	*number = strtoull(line, NULL, 10);
	*word = ft_strdup(colon + 1);
	start = *word;
	while (*start && isspace(*start))
		start++;
	end = start + ft_strlen(start) - 1;
	while (end > start && isspace(*end))
		*end-- = '\0';
	*word = ft_strdup(start);
	return (1);
}

size_t	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s) + 1;
	dup = malloc(len);
	if (!dup)
		return (NULL);
	return (memcpy(dup, s, len));
}

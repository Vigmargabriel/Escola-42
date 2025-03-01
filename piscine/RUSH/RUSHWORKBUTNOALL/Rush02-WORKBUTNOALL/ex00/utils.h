/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:52:19 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/27 15:52:25 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// utils.h
#ifndef UTILS_H
# define UTILS_H

int		is_valid_number(char *str);
int		parse_line(char *line, unsigned long long *number, char **word);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);

#endif

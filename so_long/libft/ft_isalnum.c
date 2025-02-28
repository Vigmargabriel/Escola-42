/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:25:24 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/10/21 16:47:39 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int d)
{
	if ((d >= 'A' && d <= 'Z')
		|| (d >= 'a' && d <= 'z')
		|| (d >= '0' && d <= '9'))
		return (1);
	return (0);
}

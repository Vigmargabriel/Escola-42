/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:40:31 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/18 17:40:50 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	z;
	int	a;
	int	tmp;

	z = 0;
	a = 0;
	tmp = 0;
	while (z < size)
	{
		while (a < size - 1)
		{
			if (tab[a +1] < tab[a])
			{
				tmp = tab[a +1];
				tab[a + 1] = tab[a];
				tab[a] = tmp;
				a = 0;
			}
			else
				a++;
		}
		z++;
	}
}

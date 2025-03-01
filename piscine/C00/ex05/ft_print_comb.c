/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:49:34 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/11 20:08:08 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	a;
	char	e;
	char	i;

	 a = '0';
	while (a <= '7')
	{
		e = a + 1;
		while (e <= '8')
		{
			i = e + 1;
			while (i <= '9')
			{
				write(1, &a, 1);
				write(1, &e, 1);
				write(1, &i, 1);
				if (a != '7')
					write(1, ", ", 2);
				i++;
			}
			e++;
		}
		a++;
	}
}
int	main(void)
{
	ft_print_comb();
	return (0);
}

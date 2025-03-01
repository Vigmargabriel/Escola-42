/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:01:53 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/14 20:02:04 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	handle_min_int(void)
{
	write(1, "-2147483648", 11);
}

void	ft_putnbr(int nb)
{
	char	buffer[12];
	int		i;
	int		is_negative;

	if (nb == -2147483648)
		return (handle_min_int());
	i = 0;
	is_negative = (nb < 0);
	if (is_negative)
		nb = -nb;
	if (nb == 0)
		buffer[i++] = '0';
	while (nb > 0)
	{
		buffer[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	if (is_negative)
		buffer[i++] = '-';
	while (i--)
		ft_putchar(buffer[i]);
}
/*int	main(void)
{
	ft_putnbr(42);
	return (0);
}*/

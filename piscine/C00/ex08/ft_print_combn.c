/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:00:58 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/07/15 11:01:15 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_combn(int n)
{
	char	num[10];
	int		i;
	int		j;

	if (n <= 0 || n >= 10)
		return ;
	i = -1;
	while (++i < n)
		num[i] = '0' + i;
	while (1)
	{
		write(1, num, n);
		if (num[0] == '9' - n + 1 && num[n - 1] == '9')
			break ;
		ft_putchar(',');
		ft_putchar(' ');
		i = n - 1;
		while (i >= 0 && num[i] == '9' - n + 1 + i)
			i--;
		num[i]++;
		j = i;
		while (++j < n)
			num[j] = num[j - 1] + 1;
	}
	ft_putchar('\n');
}
int	main(void)
{
	ft_print_combn(5);
	return (0);
}

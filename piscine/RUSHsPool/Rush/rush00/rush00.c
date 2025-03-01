/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abredimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 06:08:16 by abredimu          #+#    #+#             */
/*   Updated: 2024/07/13 06:08:18 by abredimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char character);

void	set_printed_chars(char printed_chars[2][2])
{
	printed_chars[0][0] = ' ';
	printed_chars[0][1] = '|';
	printed_chars[1][0] = '-';
	printed_chars[1][1] = 'o';
}

int	border(int iter_n, int n)
{
	return (iter_n == 1 || iter_n == n);
}

void	rush(int x, int y)
{
	int		iter_x;
	int		iter_y;
	char	printed_chars[2][2];

	iter_y = 1;
	set_printed_chars(printed_chars);
	while (iter_y <= y)
	{
		iter_x = 1;
		while (iter_x <= x)
		{
			ft_putchar(printed_chars[border(iter_y, y)][border(iter_x, x)]);
			iter_x++;
		}
		ft_putchar('\n');
		iter_y++;
	}
}

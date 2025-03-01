/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovack <jnovack@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:27:53 by jnovack           #+#    #+#             */
/*   Updated: 2024/07/23 15:13:53 by jnovack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

bool	is_printable(char c)
{
	if (c >= 32)
		return (true);
	else
		return (false);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		dec;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		dec = (int)str[i];
		if (is_printable(c))
			ft_putchar(c);
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[dec / 16]);
			ft_putchar("0123456789abcdef"[dec % 16]);
		}
		i++;
	}
}
/*

#include <stdbool.h>
int	main(void)
{
	char	*str;

	str = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(str);
	return (0);
}
*/

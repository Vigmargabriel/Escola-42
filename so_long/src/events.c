/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:33:16 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/12/12 20:33:18 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*ft_printf("✅ Movimentos: %d\n", game->moves);
ft_printf("\n📜 Mapa atualizado:\n");*/
int	handle_keypress(int keycode, t_game *game)
{
	int	i;

	ft_printf("🔹 Tecla pressionada: %d\n", keycode);
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D || keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		move_player(game, keycode);
		i = 0;
		while (game->map[i])
		{
			ft_printf("%s\n", game->map[i]);
			i++;
		}
	}
	return (0);
}

int	close_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	free_graphics(game);
	free_map(game->map);
	exit(0);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_game, game);
}

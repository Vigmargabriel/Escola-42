/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:24:11 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/01/09 18:59:56 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int keycode)
{
	int	new_x;
	int	new_y;

	ft_printf("\n 🔹Antes da movimentação: Posição do jogador -> X: %d, Y: %d\n",
		game->player_x, game->player_y);
	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == KEY_W || keycode == KEY_UP) // Cima
		new_y--;
	else if (keycode == KEY_S || keycode == KEY_DOWN) // Baixo
		new_y++;
	else if (keycode == KEY_A || keycode == KEY_LEFT) // Esquerda
		new_x--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT) // Direita
		new_x++;
	ft_printf("🔹Tentando mover para X: %d, Y: %d\n", new_x, new_y);
	if (!can_move_to(game, new_x, new_y))
	{
		ft_printf("⛔Movimento bloqueado!\n");
		return ;
	}
	game->map[game->player_y][game->player_x] = '0';
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.floor, //wall
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.player,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
	ft_printf("✅Depois da movimentação: Posição do jogador -> X: %d, Y: %d\n",
		game->player_x, game->player_y);
	game->moves++;
	ft_printf("Movimentos: %d\n", game->moves);
}

int	can_move_to(t_game *game, int x, int y)
{
	char	target;
	
	ft_printf("n_collectibles: %d\n", game->collectibles);
	target = game->map[y][x];
	ft_printf("can_move_to(): Tentando mover para [%d, %d] - Tile: '%c'\n",
		x, y, target);
	if (target == '1')
	{
		ft_printf("Movimento bloqueado por parede!\n");
		return (0);
	}
	if (target == 'C')
	{
		game->collectibles--;
		if (game->collectibles == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->sprites.exit,
		game->exit_x * TILE_SIZE, game->exit_y * TILE_SIZE);
	}
	if (target == 'E')
	{
		if (game->collectibles > 0)
		{
			ft_printf("Saída bloqueada, ainda há coletáveis.\n");
			return (0);
		}
		else
		{
			ft_printf("Saída alcançada! Parabéns!\n");
			close_game(game); // Termina o jogo
	  	}
  	}
   	return (1);

}

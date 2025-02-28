/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:47:36 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/01/29 16:47:38 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		print_error_and_exit(NULL, "Usage: ./so_long <map_file>");
	if (!init_game(&game, argv[1]))
		print_error_and_exit(NULL, "Failed to initialize game. Check your map.");
	ft_printf("player x: %d\n", game.player_x);
	ft_printf("player y: %d\n", game.player_y);
	if (!init_window(&game))
		print_error_and_exit(&game, "Failed to initialize window.");
	if (!load_sprites(&game))
		print_error_and_exit(&game, "Failed to load sprites.");
	render_map(&game);
	setup_hooks(&game);
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_loop(game.mlx);
	return (0);
	cleanup(&game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:18:51 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/12/12 20:18:53 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "so_long");
	if (!game->win)
	{
		free(game->mlx);
		return (0);
	}
	return (1);
}

void	count_map_dimensions(t_game *game)
{
	int	y;
	int	x;
	int	len;

	game->map_width = 0;
	game->map_height = 0;
	y = 0;
	while (game->map[y])
	{
		len = ft_strlen(game->map[y]);
		if (len > game->map_width)
			game->map_width = len;
		y++;
	}
	game->map_height = y;
	game->moves = 0;
	game->collectibles = 0;
	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			if (game->map[y][x] == 'C')
				game->collectibles++;
		}
	}
}

int init_game(t_game *game, const char *map_path)
{
    t_flood_fill    flood_fill; // Estrutura do flood_fill no header 
    char	    **map_dup;	// Mapa  duplicado (para nao mexer com o original)
    int		    valid_map; // Flag para verificar se a funcao flood_fill passou
    int		    i;
    
    game->map = read_map(map_path);
    if (!game->map)
        return (0);
    
    // Validação inicial do mapa
    if (!validate_map(game->map))
    {
        free_map(game->map);
        return (0);
    }
    // Calcula dimensões do mapa e localiza elementos
    count_map_dimensions(game);
    
    // Prencehr dados da Estrutura do flood_fill no header
    flood_fill.collectibles = game->collectibles;
    flood_fill.exit_found = 0;
    
    // Cria o Mapa duplicado
    map_dup = ft_duplicate_map(game->map);

    // Rodar Flood_Fill
    valid_map = ft_flood_fill(map_dup, game->player_x, game->player_y, &flood_fill);
    
    //Libertar o Mapa Duplicado
    i = -1;
    while (++i < game->map_height)
    	free(map_dup[i]);
    free(map_dup);
    
    //Verificar se Flood_Fill passou
    if (!valid_map)
    {
        free_map(game->map);
        return (0);
    }	
    return (1);
}

int	load_sprites(t_game *game)
{
	int	width;
	int	height;

	if (!game->mlx)
	{
		print_error_and_exit(game,
			"MiniLibX not initialized before loading sprites.");
		return (0);
	}
	game->sprites.wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &width, &height);
	game->sprites.floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &width, &height);
	game->sprites.player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &width, &height);
	game->sprites.collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	game->sprites.exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &width, &height);
	game->sprites.exit_blocked = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_blocked.xpm", &width, &height); // Novo sprite

	if (!game->sprites.wall || !game->sprites.floor || !game->sprites.player
		|| !game->sprites.collectible || !game->sprites.exit
		|| !game->sprites.exit_blocked) // Verifica se exit_blocked também foi carregado
	{
		free_graphics(game);
		return (0);
	}
	return (1);
}

void render_map(t_game *game)
{
    int x;
    int y;
    void *sprite;

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            sprite = NULL;
            if (game->map[y][x] == '1')
                sprite = game->sprites.wall;
            else if (game->map[y][x] == '0')
                sprite = game->sprites.floor;
            else if (game->map[y][x] == 'P')
                sprite = game->sprites.player;
            else if (game->map[y][x] == 'C')
                sprite = game->sprites.collectible;
            else if (game->map[y][x] == 'E')
            {
                sprite = game->sprites.exit_blocked; // Sprite para saída acessível
                game->exit_x = x;
                game->exit_y = y;
            }
            if (sprite)
                mlx_put_image_to_window(game->mlx, game->win, sprite,
                    x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}

void	free_graphics(t_game *game)
{
	if (game->sprites.wall)
		mlx_destroy_image(game->mlx, game->sprites.wall);
	if (game->sprites.floor)
		mlx_destroy_image(game->mlx, game->sprites.floor);
	if (game->sprites.player)
		mlx_destroy_image(game->mlx, game->sprites.player);
	if (game->sprites.collectible)
		mlx_destroy_image(game->mlx, game->sprites.collectible);
	if (game->sprites.exit)
		mlx_destroy_image(game->mlx, game->sprites.exit);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
}

void	free_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->sprites.wall)
		mlx_destroy_image(game->mlx, game->sprites.wall);
	if (game->sprites.floor)
		mlx_destroy_image(game->mlx, game->sprites.floor);
	if (game->sprites.player)
		mlx_destroy_image(game->mlx, game->sprites.player);
	if (game->sprites.collectible)
		mlx_destroy_image(game->mlx, game->sprites.collectible);
	if (game->sprites.exit)
		mlx_destroy_image(game->mlx, game->sprites.exit);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

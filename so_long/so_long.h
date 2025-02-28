/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:22:23 by vigde-ol          #+#    #+#             */
/*   Updated: 2025/01/09 19:22:25 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h> // Para malloc, free, etc.
# include <unistd.h> // Para write
# include "libft.h"
# include "mlx.h"
# include "so_long.h"
# include <fcntl.h>   // Para open
# include <stdbool.h> // Para usar 'bool', caso necessário
# include <stddef.h> // Adiciona suporte para NULL

// Outras funções e declarações
int	is_valid_char(char c);
int	has_required_elements(char **map);

// Definições de macros
# define TILE_SIZE 32
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

// Estrutura para sprites
typedef struct s_sprites
{
    void    *wall;
    void    *floor;
    void    *player;
    void    *collectible;
    void    *exit;
    void    *exit_blocked;   // Saída bloqueada
}   t_sprites;

// Estrutura principal do jogo
typedef struct s_game
{
	void	*mlx; // Conexão com o MiniLibX
	void	*win; // Janela do jogo
	char	**map; // Mapa do jogo
	int	map_width; // Largura do mapa
	int	map_height; // Altura do mapa
	int	player_x; // Posição X do jogador
	int	player_y; // Posição Y do jogador
	int	exit_x; // Foi chamado para mostrar a posicao da saida
	int	exit_y; // Foi chamado para mostrar a posicao da saida
	int	moves;  // Contador de movimentos
	int	collectibles; // Quantidade de itens a coletar
	t_sprites	sprites;
	int	tile_width;   // Adicionado
	int	tile_height;  // Adicionado
	int	exit_found;	//Variavel para verificar se a saida foi encontrada
}   t_game;

typedef struct s_flood_fill
{
	int			collectibles;
	int			exit_found;
}				t_flood_fill;

//                  ************* Protótipos de funções *********************

// events.c
int     handle_keypress(int keycode, t_game *game);
int	close_game(t_game *game);
void    setup_hooks(t_game *game);


// game.c
int     init_window(t_game *game);
void	count_map_dimensions(t_game *game);
int	init_game(t_game *game, const char *map_path);
int     load_sprites(t_game *game);
void	free_game(t_game *game);
void    render_map(t_game *game);
void free_graphics(t_game *game);

// main.c
int main	(int argc, char **argv);

// map.c
int	count_lines(int fd);
char    **read_map(const char *file_path);
int     validate_map(char **map);
int	is_valid_char(char c);
int	has_required_elements(char **map);
int	collectible_surrounded(char **map, size_t rows, size_t cols);
int	ft_flood_fill(char **map, int x, int y, t_flood_fill *flood_fill);
char	**ft_duplicate_map(char **map);

// player.c
void    move_player(t_game *game, int keycode);
int     can_move_to(t_game *game, int x, int y);

// utils.c
void    free_map(char **map);
void    print_error(char *message);
void	print_error_and_exit(t_game *game, char *message);
void	cleanup(t_game *game);

#endif

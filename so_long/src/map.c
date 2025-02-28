/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:58:13 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/12/12 16:28:57 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	count_lines(int fd)
{
	char	*line;
	int		count;

	count = 0;
	while ((line = get_next_line(fd)))
	{
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

char	**read_map(const char *file_path)
{
	int		fd;
	int		i;
	int		lines;
	char	**map;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = count_lines(fd);
	if (lines <= 0)
	{
		close(fd);
		return (NULL);
	}
	map = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (free(map), NULL);
	i = -1;
	while (++i < lines)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			while (i >= 0)
				free(map[i--]);
			return (free(map), close(fd), NULL);
		}
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
	}
	map[lines] = NULL;
	close(fd);
	return (map);
}
//Verifica se coletáveis estão cercados por paredes
int	collectible_surrounded(char **map, size_t rows, size_t cols)
{
	size_t	i;
	size_t	j;

	i = 1; // Começa da segunda linha, ignorando a borda
	while (i < rows - 1) // Evita verificar a última linha
	{
		j = 1; // Começa da segunda coluna
		while (j < cols - 1) // Evita verificar a última coluna
		{
			if (map[i][j] == 'C') // Encontra um coletável
			{
				// Verifica se está cercado por paredes
				if (map[i - 1][j] == '1' && map[i + 1][j] == '1' &&
					map[i][j - 1] == '1' && map[i][j + 1] == '1')
					return (printf("Erro: Coletável cercado por paredes.\n"), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
// 🔹 Valida o mapa
int	validate_map(char **map)
{
	size_t	rows;
	size_t	cols;
	size_t	i;
	size_t	j;

	if (!map || !map[0])
		return (printf("Erro: Mapa não encontrado ou vazio.\n"), 0);
	rows = 0;
	cols = ft_strlen(map[0]);
	while (map[rows])
		rows++;
	if (rows < 3 || cols < 3)
		return (printf("Erro: Mapa muito pequeno.\n"), 0);
	i = -1;
	while (++i < rows)
	{
		if (ft_strlen(map[i]) != cols)
			return (printf("Erro: Mapa não é retangular.\n"), 0);
		j = -1;
		while (++j < cols)
		{
			if (!is_valid_char(map[i][j]))
				return (printf("Erro: Caractere inválido detectado.\n"), 0);
			if ((i == 0 || i == rows - 1 || j == 0 || j == cols - 1) &&
				map[i][j] != '1')
				return (printf("Erro: Paredes externas incorretas.\n"), 0);
		}
	}
	//Verificar se ha coletaveis cercados
	if (collectible_surrounded(map, rows, cols))
		return(0);
	if (!has_required_elements(map))
		return (printf("Erro: Faltam elementos obrigatórios (P, C, E).\n"), 0);
	return (1);
}
// 🔹 Verifica se caractere é válido
int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E');
}
// 🔹 Verifica se há elementos obrigatórios
int	has_required_elements(char **map)
{
	size_t	i;
	size_t	j;
	int		p_count;
	int		c_count;
	int		e_count;

	i = 0;
	p_count = 0;
	c_count = 0;
	e_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p_count++;
			else if (map[i][j] == 'C')
				c_count++;
			else if (map[i][j] == 'E')
				e_count++;
			j++;
		}
		i++;
	}
	return (p_count == 1 && c_count > 0 && e_count > 0);

	if (!has_required_elements(map))
		return (printf("Erro: Faltam elementos obrigatórios (P, C, E).\n"), 0);
	return (1);
}

char	**ft_duplicate_map(char **map)
{
	int		i;
	int		rows;
	char	**copy;

	rows = 0;
	while (map[rows])
		rows++;
	copy = (char **)malloc((rows + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < rows)
		copy[i] = ft_strdup(map[i]);
	copy[i] = NULL;
	return (copy);
}

int	ft_flood_fill(char **map, int x, int y, t_flood_fill *flood_fill)
{
	if (x < 0 || y < 0 || !map[y] || map[y][x] == '1' || map[y][x] == '\0')
		return (0);
	if (map[y][x] == 'C')
		flood_fill->collectibles--;
	if (map[y][x] == 'E')
	{
		flood_fill->exit_found = 1;
		if (!flood_fill->collectibles)
			return (1);
		return (0);
	}
	map[y][x] = '1';
	if (!flood_fill->collectibles && flood_fill->exit_found)
		return (1);
	if (ft_flood_fill(map, x + 1, y, flood_fill)
		|| ft_flood_fill(map, x - 1, y, flood_fill)
		|| ft_flood_fill(map, x, y + 1, flood_fill)
		|| ft_flood_fill(map, x, y - 1, flood_fill))
		return (1);
	return (0);
}

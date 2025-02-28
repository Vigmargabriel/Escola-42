/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:39:32 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/10/21 18:48:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_personal.h"

static char	*ft_free(char *buffer, const char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

/*
** ft_free:
** Junta o conteúdo de `buffer` e `buf`, atualizando `buffer` 
e liberando a memória antiga.
** Retorna o novo `buffer` concatenado.
*/

static char	*ft_line(const char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/*
** ft_line:
** Extrai uma linha completa de `buffer`, finalizando-a no primeiro `\n`.
** Retorna a linha extraída como uma nova string.
*/

static char	*ft_next(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!new_buffer)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

/*
** ft_next:
** Prepara o `buffer` para a próxima linha, removendo a linha já lida.
** Retorna o `new_buffer` com o conteúdo restante.
*/

static char	*read_file(int fd, char *buffer)
{
	char	*buf;
	int		byte_read;

	if (!buffer)
	{
		buffer = malloc (1 * sizeof(char));
		buffer[0] = '\0';
	}
	buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buf)
		return (free(buffer), NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(buffer), free(buf), NULL);
		buf[byte_read] = '\0';
		buffer = ft_free(buffer, buf);
		if (!buffer || ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (buffer);
}

/*
** read_file:
** Lê continuamente do arquivo `fd` e acumula os dados em `buffer`.
** Interrompe a leitura ao encontrar um `\n` ou o final do arquivo.
** Retorna o `buffer` atualizado.
*/

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}

/*
** get_next_line:
** Função principal para ler e retornar uma linha de um
 arquivo com `fd` especificado.
** Usa `buffer` para manter dados entre chamadas.
** Retorna a linha lida ou NULL se não houver mais dados 
ou em caso de erro.
*/

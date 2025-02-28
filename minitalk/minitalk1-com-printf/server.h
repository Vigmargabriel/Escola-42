/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:08:01 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/12/03 17:08:14 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*
 * Estrutura para armazenar o estado da mensagem recebida.
 */
typedef struct s_message
{
	char	current_char;
	int		bit_index;
}	t_message;

#endif

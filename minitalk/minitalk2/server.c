/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42luxembou>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:43:27 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/12/03 16:43:58 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "ft_printf/ft_printf.h" // Inclua o cabeçalho do ft_printf

t_message	g_msg = {0, 7};

void	handle_signal(int signum)
{
	if (signum == SIGUSR1)
		g_msg.current_char |= (1 << g_msg.bit_index);
	else if (signum == SIGUSR2)
		g_msg.current_char &= ~(1 << g_msg.bit_index);
	g_msg.bit_index--;
	if (g_msg.bit_index < 0)
	{
		if (g_msg.current_char == '\0')
			write(1, "\n", 1);
		else
			write(1, &g_msg.current_char, 1);
		g_msg.current_char = 0;
		g_msg.bit_index = 7;
	}
}

void	setup_signal_handlers(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(2, "Error setting up signal handlers\n", 33);
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid); // Substituído por ft_printf
	setup_signal_handlers();
	while (1)
		pause();
	return (0);
}

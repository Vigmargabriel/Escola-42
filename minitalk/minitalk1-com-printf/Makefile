# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vigde-ol <vigde-ol@student.42luxembou      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 16:44:40 by vigde-ol          #+#    #+#              #
#    Updated: 2024/12/03 16:44:44 by vigde-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

server: server.c
	$(CC) $(CFLAGS) -o server server.c

client: client.c
	$(CC) $(CFLAGS) -o client client.c

clean:
	rm -f server client

fclean: clean

re: fclean all


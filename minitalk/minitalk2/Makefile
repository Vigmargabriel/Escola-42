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

# Fontes principais
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

# Objetos derivados dos fontes
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# Caminho da biblioteca ft_printf
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME)

# Regras para o servidor (linkando a libftprintf.a)
server: $(OBJS_SERVER) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o server $(OBJS_SERVER) $(FT_PRINTF)

# Regras para o cliente (não precisa da libftprintf.a)
client: $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o client $(OBJS_CLIENT)

# Compilação da libftprintf.a
$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

# Limpeza de objetos
clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	make clean -C $(FT_PRINTF_DIR)

# Limpeza completa
fclean: clean
	rm -f server client
	make fclean -C $(FT_PRINTF_DIR)

# Recompilação total
re: fclean all

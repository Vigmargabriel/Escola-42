# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vigde-ol <vigde-ol@student.42luxembou      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 16:26:06 by vigde-ol          #+#    #+#              #
#    Updated: 2024/12/12 16:26:08 by vigde-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = minilibx-linux
LIBFT = libft
LIBFT_A = $(LIBFT)/libft.a
LIBS = -L$(MLX) -lmlx -lXext -lX11 -lm
# Para Linux:
# LIBS = -L$(MLX) -lmlx -lXext -lX11 -lm -lz

SRC_DIR = src
OBJ_DIR = obj
SRCS =	$(SRC_DIR)/main.c $(SRC_DIR)/map.c $(SRC_DIR)/game.c\
	$(SRC_DIR)/player.c $(SRC_DIR)/events.c $(SRC_DIR)/utils.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(MLX) $(LIBFT_A) $(NAME)

$(MLX):
	make -C $(MLX)

$(LIBFT_A):
	make -C $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -Ilibft -Iminilibx-linux -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

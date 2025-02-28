# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 19:27:18 by vigde-ol          #+#    #+#              #
#    Updated: 2024/10/22 19:59:09 by vigde-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome da biblioteca
NAME = libft_personal.a

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
sleep = 0.05

# Arquivos de origem libft, fr_printf e get_nex_line sucessivamente
SRCS = $(wildcard *.c)
	
# Arquivos bônus libft (listas encadeadas)
BONUS_SRCS = $(wildcard *.c)

# Gera os arquivos objetos de todos libft, ft_printf e get_next_line
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

#****************************************************************************************# 
#                                     Regras do Makefile                                 #
#****************************************************************************************#
                            
# Regra all: Compila os arquivos e cria a biblioteca
all: $(NAME)

# Regra para compilar a biblioteca principal
$(NAME): $(OBJS)
	@printf "Compiling [$(y)$(NAME)$(r)]: executable$(c)\r"
	@sleep $(sleep) 
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "Compiling [$(y)$(NAME)$(r)]: $(g)Success$(r)$(c)\n"

# Regra para compilar os arquivos .o a partir dos .c
%.o: %.c 
	@printf "Compiling [$(y)$(NAME)$(r)]: $(notdir $@)$(c)\r"
	@sleep $(sleep)
	@$(CC) $(CFLAGS) -c $< -o $@
	
# Alvo bônus: compila a biblioteca incluindo os bônus
bonus: $(OBJS) $(BONUS_OBJS)
	@printf "Compiling [$(y)$(NAME)$(r)]: $(notdir $@)$(c)\r"
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@ranlib $(NAME)
	@printf "Compiling [$(y)$(NAME)$(r)]: $(g)Success$(r)$(c)\n"
# Regra clean: Remove os arquivos objetos (.o)
clean:
	@printf "Removing [$(p)objects$(r)]: objects$(c)\r"
	@sleep $(sleep)
	@rm -f $(OBJS) $(BONUS_OBJS)
	@printf "Removing [$(p)objects$(r)]: $(g)Success$(r)$(c)\n"

# Regra fclean: Remove os arquivos objetos (.o) e a biblioteca (libft.a)
fclean: clean
	@printf "Removing [$(p)$(NAME)$(r)]: $(NAME)$(c)\r"
	@sleep $(sleep)
	@rm -f $(NAME)
	@printf "Removing [$(p)$(NAME)$(r)]: $(g)Success$(r)$(c)\n"

# Regra re: Limpa tudo e recompila
re: fclean all

#unit-tester era somente para o tester da LIBFT
#so:
	#$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	#gcc -nostartfiles -shared -o personal_libft.so $(OBJS) $(BONUS_OBJS)

# Declaração de alvos que não são arquivos
.PHONY: all clean fclean re bonus

# Colours
c	= \033[K
p	= \033[38;2;255;0;127m #rosa choque vibrante
y	= \033[38;2;255;215;0m #amarelo ouro
g	= \033[38;2;50;205;50m #verde grama brilhante
b	= \033[1m
r	= \033[0m

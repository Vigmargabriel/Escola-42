# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 20:06:09 by vigde-ol          #+#    #+#              #
#    Updated: 2025/02/14 20:06:13 by vigde-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
sleep = 0.05

LIBFT_PERSONAL = libft_personal/libft_personal.a
SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_PERSONAL)
	@printf "Compiling [$(y)$(NAME)$(r)]:executable$(c)\r"
	@sleep $(sleep)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -Llibft_personal -lft_personal
	@printf "Compiling [$(y)$(NAME)$(r)]:$(g)Success$(r)$(c)\n"
	

$(LIBFT_PERSONAL):
	@cd libft_personal && $(MAKE) --no-print-directory

%.o: %.c
	@printf "Compiling [$(y)$(NAME)$(r)]: $(notdir $@)$(c)\r"
	@sleep $(sleep)
	@$(CC) $(CFLAGS) -c $< -o $@ -I./

clean:
	@printf "Removing [$(p)objects$(r)]: objects$(c)\r"
	@sleep $(sleep)
	@cd libft_personal && $(MAKE) clean --no-print-directory
	@rm -f $(OBJ)
	@printf "Removing [$(p)objects$(r)]: $(g)Success$(r)$(c)\n"

fclean: clean
	@printf "Removing [$(p)$(NAME)$(r)]: $(NAME)$(c)\r"
	@sleep $(sleep)
	@cd libft_personal && $(MAKE) fclean --no-print-directory
	@rm -f $(NAME)
	@printf "Removing [$(p)$(NAME)$(r)]: $(g)Success$(r)$(c)\n"

re: fclean all

.PHONY = all clean fclean re

# Colours
c	= \033[K
p	= \033[38;2;0;102;204m #azul bic
y	= \033[38;2;255;102;0m #laranja fluorescente
g	= \033[38;2;191;0;255m #roxo fluorescente
b	= \033[1m #texto em negrito
r	= \033[0m #Reset (Volta ao normal, sem cor ou estilo).

#-Llibft_personal -lft_personal
#-L =  A flag -L diz onde procurar bibliotecas. sintaxe= -L<caminho_da_pasta> 
#	exemplo:
#		-Llibft_personal
#			Aqui, o linker procurará bibliotecas dentro da pasta libft_personal/.
#-l A flag -l diz qual biblioteca linkar. 
#sintaxe= -l<nome_da_biblioteca>
#	🔹 O linker procura por um arquivo chamado lib<nome_da_biblioteca>.a ou lib<nome_da_biblioteca>.so nos diretórios especificados por -L e nos diretórios padrão do sistema.
#		exemplo:
#			-lm
#				Isso linka a biblioteca libm.a ou libm.so (math library).
#⚠️ IMPORTANTE:
#Quando você usa -lNOME, o linker procura automaticamente por libNOME.a ou libNOME.so.
#Se sua biblioteca não tem o prefixo lib, use -l:arquivo.a.
#
#📌 Exemplo errado:

#-llibft_personal
#Isso tenta encontrar liblibft_personal.a, mas sua biblioteca se chama libft_personal.a.
#
#📌 Exemplo correto:#

#-l:libft_personal.a
#Isso diz ao linker para usar exatamente esse nome, sem o prefixo lib.

#Exemplo completo no Makefile
#Se sua biblioteca está em libft_personal/libft_personal.a e você não quer renomeá-la, use:

#-Llibft_personal -l:libft_personal.a
#Se você renomear para liblibft_personal.a, pode usar:

#-Llibft_personal -llibft_personal
#SRC = $(wildcard src/*.c) se colocar o src somente ja pega todos os arquivos.	

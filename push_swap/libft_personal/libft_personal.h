/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:14:07 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/10/22 20:16:23 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PERSONAL_H
# define LIBFT_PERSONAL_H

# include <stdarg.h>
# include <stddef.h> // Para size_t
# include <stdlib.h> // Para malloc, calloc
# include <stdlib.h>
# include <unistd.h> // Para write

/* ************************************************************************** */
/*                           Parte 1 - Funções da libft                       */
/* ************************************************************************** */

/* Funções de checagem de caracteres */
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

/* Funções de manipulação de strings */
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dest, const char *src, size_t size);

/* Funções de manipulação de memória */
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);

/* Funções de conversão de caracteres */
int					ft_toupper(int c);
int					ft_tolower(int c);

/* Funções de conversão de strings para números */
int				ft_atoi(const char *str);

/* Funções adicionais que usam malloc */
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s1);

/* ************************************************************************** */
/*                         Parte 2 - Funções Adicionais                       */
/* ************************************************************************** */

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/* ************************************************************************** */
/*                            Parte Bonus - Listas - libft                    */
/* ************************************************************************** */

/* Estrutura para a lista encadeada */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* Funções para manipulação de listas */
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/* ************************************************************************** */
/*                            get_next_line                                   */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Função principal
char				*get_next_line(int fd);

// Funções auxiliares definidas em get_next_line_utils.c
// foi retirado o protótipo de ft_calloc que estava gerando problema
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);

/* ************************************************************************** */
/*                            ft_printf                                       */
/* ************************************************************************** */

// Protótipo da função principal ft_printf
int					ft_printf(const char *format, ...);
void				ft_process_format(va_list *args, const char *format,
						int *count);

// Funções de conversão para cada tipo de formato
int					ft_print_char(char c);
void				ft_process_format(va_list *args, const char *format,
						int *count);
int					ft_printf(const char *format, ...);
int					ft_print_hex_lower(unsigned int num);
int					ft_print_hex_upper(unsigned int num);
int					ft_print_int(int n);
int					ft_print_percent(void);
int					ft_print_pointer(void *ptr);
int					ft_print_string(char *str);
void				ft_put_unsigned_fd(unsigned int n, int fd);
int					ft_print_unsigned(unsigned int n);

// Função auxiliar para impressão de números inteiros
void				ft_putnbr_fd(int n, int fd);
/*

nunca declarar dentro de um arquivo.h uma funcao static, nao precisa.

# include <stdlib.h>
Este cabeçalho contém funções padrão da biblioteca C 
relacionadas a alocação de memória,
	conversão de tipos e geração de números aleatórios. 
	Algumas funções comuns que estão disponíveis nesse cabeçalho são:

malloc(), free() → Alocação e liberação de memória.
atoi(), itoa(), strtol() → Conversão de strings para números inteiros.
exit() → Termina o programa.
No caso do ft_printf, o stdlib.h pode ser útil se você precisar, por exemplo,
	de alocação dinâmica de memória dentro da implementação 
	da função de impressão.

# include <stdarg.h>
Esse cabeçalho é essencial para a implementação de ft_printf,
	pois ele permite trabalhar com argumentos variáveis.
	 O printf tradicional aceita um número variável de argumentos (exemplo:
	%d, %s, %x), e para fazer isso em C, usamos a biblioteca stdarg.h,
	que contém macros para manipulação de argumentos variáveis.

Principais macros de stdarg.h:
va_list → Declara uma variável para armazenar os argumentos.
va_start() → Inicia a leitura dos argumentos variáveis.
va_arg() → Obtém o próximo argumento da lista.
va_end() → Finaliza o processamento dos argumentos.

*/
#endif

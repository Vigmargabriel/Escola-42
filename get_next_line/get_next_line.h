#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Função principal
static char	*ft_free(char *buffer, const char *buf);
static char	*ft_line(const char *buffer);
static char	*ft_next(char *buffer);
static char	*read_file(int fd, char *buffer);
char		*get_next_line(int fd);

// Funções auxiliares definidas em get_next_line_utils.c
// foi retirado o protótipo de ft_calloc que estava gerando problema
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

#endif

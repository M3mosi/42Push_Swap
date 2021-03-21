/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:24:26 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/21 22:12:23 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define MAX_FILES 4096
# define BUFFER_SIZE 1
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_flags
{
	int minus;
	int size;
	int terminator;
	int point;
	int zero;
}					t_flags;

int					ft_get_next_line(int fd, char **line);
char				*ft_recalloc(char *line_old, ssize_t plus);
int					ft_atoi(const char *nptr);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nelem, size_t elsize);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strndupfill(const char *s, size_t n, char fill);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char **s1, char const *set, int mod);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isspace(int c);
int					ft_iscontain(char c, char const *set);
char				*ft_strncpy(char *dest, char *src, size_t n, size_t i);
int					ft_atoi_abs(const char *nptr);
int					ft_core_digit(char *str, t_flags *flags, va_list *args);
int					ft_core_minus(char *str, t_flags *flags, va_list *args);
int					ft_core_point(char *str, t_flags *flags, va_list *args);
int					ft_core_print(char *str, t_flags *flags, va_list *args);
int					ft_core_star(char *str, t_flags *flags, va_list *args);
int					ft_core_zero(char *str, t_flags *flags, va_list *args);
t_flags				ft_initflags(t_flags flags);
int					ft_isterminator(int c);
char				*ft_itoa_base_unsigned_long(size_t number, int base);
char				*ft_itoa_base_unsigned(unsigned int number, int base);
char				*ft_itoa_base(int number, int base);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
int					ft_print_char(t_flags *flags, int c);
int					ft_print_decimal_neg(t_flags *flags, char *num);
int					ft_print_decimal_unsigned(t_flags *flags, int n);
int					ft_print_decimal(t_flags *flags, int n);
int					ft_print_exa(t_flags *flags, size_t n, int u);
int					ft_print_percent(t_flags *flags);
int					ft_print_pointer_null(t_flags *flags);
int					ft_print_pointer(t_flags *flags, size_t ptr);
int					ft_print_string(t_flags *flags, char *str);
int					ft_print_zero(t_flags *flags);
int					ft_printf(const char *str, ...);
int					ft_putlchar(char c);
int					ft_putlstr(char *s, int len);
char				*ft_toupperstr(char *str);
int					ft_strnbr(const char *str);
int 				ft_matrix_len(char **matrix);
void				ft_free_matrix(void **matrix, int len);
void				ft_print_matrix(char **matrix, char *prefix);
void				ft_print_arrint(int *arr, int len, char *prefix);

#endif

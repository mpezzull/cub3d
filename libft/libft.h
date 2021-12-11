/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:41:05 by mpezzull          #+#    #+#             */
/*   Updated: 2021/04/26 15:41:05 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);
void			ft_putstr_fd(char *s, int fd);
void			*ft_memset(void *dest, int val, size_t len);
void			ft_bzero(void *s, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t len);
int				ft_memcmp(const void *str1, const void *str2, size_t count);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *s, int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
void			*ft_memchr(const void *src_void, int c, size_t length);
void			*ft_calloc(size_t n, size_t size);
int				ft_isalnum(int c);
int				ft_isprint(int c);
char			*ft_itoa(int num);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isascii(int c);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strdup(const char *src);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t			ft_strlcpy(char *dst, char *src, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
#endif

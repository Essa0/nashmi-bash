/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:12:51 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/30 10:05:46 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdint.h> // SIZE_MAX
# include <unistd.h>

int		ft_atoi(const char *nptr); //1 *

void	ft_bzero(void *s, size_t n); // 2 * 

int		ft_isalnum(int c); // 3 * 

int		ft_isalpha(int c); //4 *

int		ft_isascii(int c); // 5 * 

int		ft_isdigit(int c); // 6 *

int		ft_isprint(int c); // 7 *

void	*ft_memchr(const void *s, int c, size_t n); //8  *

int		ft_memcmp(const void *s1, const void *s2, size_t n); // 9 *

void	*ft_memcpy(void *dest, const void *src, size_t n); // 10 *

void	*ft_memmove(void *dest, const void *src, size_t n); // 11 * 

void	*ft_memset(void *s, int c, size_t n); // 12 *

char	*ft_strchr(const char *str, int c); // 13 *

size_t	ft_strlcat(char *dst, const char *src, size_t size); // 14 *

size_t	ft_strlcpy(char *dst, const char *src, size_t size); // 15 *

size_t	ft_strlen(const char *s); // 16 *

int		ft_strncmp(const char *s1, const char *s2, size_t n); // 17 *

char	*ft_strnstr(const char *big, const char *little, size_t len); // 18 *

char	*ft_strrchr(const char *s, int c); // 19 * 

int		ft_tolower(int c); // 20 *

int		ft_toupper(int c); // 21 *

void	*ft_calloc(size_t nmemb, size_t size); // 22 *

char	*ft_strdup(const char *s); // 23 * 

char	*ft_substr(char const *s, unsigned int start, size_t len); // 1 *

char	*ft_strjoin(char const *s1, char const *s2); // 2 * 

char	*ft_strtrim(char const *s1, char const *set); // 3 * 

char	**ft_split(char const *s, char c); // 4 *

char	*ft_itoa(int n); // 5 *

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char)); // 6 *

void	ft_striteri(char *s, void (*f)(unsigned int, char*)); // 7 *

void	ft_putchar_fd(char c, int fd); // 8 *

void	ft_putstr_fd(char *s, int fd); // 9 *

void	ft_putendl_fd(char *s, int fd); // 10 *

void	ft_putnbr_fd(int n, int fd); // 11 *

int		ft_isspace(int c);

int		ft_strcmp(const char *s1, const char *s2);

#endif

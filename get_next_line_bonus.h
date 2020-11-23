/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 02:19:53 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/23 22:33:54 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif
# ifndef FD_SIZE
#  define FD_SIZE 64
# endif
# ifndef STACK_SIZE
#  define STACK_SIZE 30000
# endif
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strncpy(char *dst, char *src, size_t n);
void	ft_bzero(void *s, size_t n);

#endif

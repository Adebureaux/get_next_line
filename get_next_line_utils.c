/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 15:04:36 by adeburea          #+#    #+#             */
/*   Updated: 2020/10/13 20:10:06 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char*)&s[i]);
		i++;
	}
	return ((c == '\0') ? (char*)&s[i] : NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s1) + 1;
	dst = malloc(len);
	if (ft_strlcpy(dst, s1, len) == len - 1)
		return (dst);
	free(dst);
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char *dst;

	while (start-- && *s)
		s++;
	if (!(dst = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strlcpy(dst, s, len + 1);
	return (dst);
}

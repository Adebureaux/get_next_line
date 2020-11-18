/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 21:53:59 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/18 02:54:58 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	s_save[30000];

int		get_size(int c)
{
	int i;

	i = 0;
	while (s_save[i] != c && s_save[i])
		i++;
	if (s_save[i] == c)
		return (i);
	return (-1);
}

void	get_sub_save(int start, int len)
{
	int		i;
	char	*tmp;

	i = 0;
	while (start-- && s_save[i])
		i++;
	tmp = ft_strndup(s_save + i + 1, len);
	ft_strncpy(s_save, tmp, len);
	free(tmp);
}

int		get_file(int fd)
{
	int rd;

	if (read(fd, &rd, 0) == -1)
		return (0);
	rd = 1;
	while (rd > 0 && get_size('\n') == -1)
	{
		rd = read(fd, &s_save[ft_strlen(s_save)], BUFFER_SIZE);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int		len;
	int		ret;
	char	*dst;

	ret = 1;
	dst = NULL;
	if (!get_file(fd) || !line || BUFFER_SIZE < 1 || fd < 0)
		return (-1);
	if ((len = get_size('\n')) == -1)
	{
		len = ft_strlen(s_save);
		ret = 0;
	}
	if (s_save[0])
		dst = ft_strndup(s_save, len);
	else
	{
		if (!(dst = malloc(1)))
			return (-1);
		dst[0] = '\0';
	}
	get_sub_save(len, ft_strlen(s_save));
	*line = dst;
	return (ret);
}

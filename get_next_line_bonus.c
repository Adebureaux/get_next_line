/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 21:53:59 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/23 22:40:20 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_size(int c, char *save)
{
	int i;

	i = 0;
	while (save[i] && save[i] != c)
		i++;
	if (save[i] == c)
		return (i);
	return (-1);
}

void	get_sub_save(int start, char *save)
{
	int		i;
	int		len;
	char	*tmp;

	len = ft_strlen(save);
	i = 0;
	while (save[i] && start--)
		i++;
	tmp = ft_strndup(save + i + 1, len);
	ft_strncpy(save, tmp, len);
	free(tmp);
}

int		get_file(int fd, char *save)
{
	int rd;

	if (read(fd, &rd, 0) == -1)
		return (0);
	rd = 1;
	if (!save[0])
		ft_bzero(save, STACK_SIZE + BUFFER_SIZE);
	while (rd > 0 && get_size('\n', save) == -1)
		rd = read(fd, &save[ft_strlen(save)], BUFFER_SIZE);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	save[FD_SIZE][STACK_SIZE + BUFFER_SIZE];
	int			len;
	int			ret;
	char		*dst;

	ret = 1;
	if (!get_file(fd, save[fd]) || !line || BUFFER_SIZE < 1 || fd < 0)
		return (-1);
	if ((len = get_size('\n', save[fd])) == -1)
	{
		len = ft_strlen(save[fd]);
		ret = 0;
	}
	if (save[fd][0])
		dst = ft_strndup(save[fd], len);
	else
	{
		if (!(dst = malloc(1)))
			return (-1);
		dst[0] = '\0';
	}
	get_sub_save(len, save[fd]);
	*line = dst;
	return (ret);
}

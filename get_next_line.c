/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 21:53:59 by adeburea          #+#    #+#             */
/*   Updated: 2020/10/19 01:55:25 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	g_save[1024];

int		get_size(void)
{
	int i;

	i = 0;
	while (g_save[i] != '\n' && g_save[i])
		i++;
	if (g_save[i] == '\n')
		return (i);
	return (0);
}

void	get_sub_save(int start, int len)
{
	int		i;
	char	*tmp;

	i = 0;
	while (start-- && g_save[i])
		i++;
	tmp = ft_strndup(g_save + i + 1, len);
	ft_strncpy(g_save, tmp, len);
	free(tmp);
}

int		get_file(int fd)
{
	int	rd;

	while ((rd = read(fd, &g_save[ft_strlen(g_save)], BUFFER_SIZE)))
	{
		if (get_size() || !rd || g_save[0] == '\n')
			break ;
	}
	return (rd);
}

int		get_next_line(int fd, char **line)
{
	int		rd;
	int		len;
	char	*ret;

	ret = NULL;
	if (!line || BUFFER_SIZE < 1 || fd < 0 || read(fd, ret, 0) == -1)
		return (-1);
	rd = get_file(fd);
	len = !rd && g_save[0] ? ft_strlen(g_save) : get_size();
	if (g_save[0])
		ret = ft_strndup(g_save, len);
	get_sub_save(len, ft_strlen(g_save));
	*line = ret;
	if (rd)
		return (1);
	return (0);
}

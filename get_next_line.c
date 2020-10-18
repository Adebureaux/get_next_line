#include "get_next_line.h"

static char	save[1024];

int		get_size(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n' && s[i] != EOF && s[i])
		i++;
	printf("%d\n", i);
	if (s[i] == '\n' || s[i] == EOF)
		return (i);
	return (0);
}

void	parse_save(int start, int len)
{
	int		i;
	char	*tmp;

	i = 0;
	while (start-- && save[i])
			i++;
	tmp = strndup(save + i + 1, len);
	strncpy(save, tmp, 1024);
	free(tmp);
}

void	get_line(int fd)
{
	int rd;
	int i;

	rd = 1;
	i = ft_strlen(save);
	while (!ft_strchr(save, '\n') && rd > 0)
	{
		rd = read(fd, &save[i], BUFFER_SIZE);
		printf("buffer while = |%s|\n", save);
		if (rd > 0)
			i += rd;
	}
}

int		get_next_line(int fd, char **line)
{
	int		len;
	char	*ret;

	ret = NULL;
	if (!line || !BUFFER_SIZE || fd < 0 || read(fd, ret, 0) == -1)
		return (-1);
	printf("buffer first = |%s|\n", save);
	if (!ft_strchr(save, '\n') && !ft_strchr(save, EOF))
		get_line(fd);
	len = get_size(save);
	if (save[0])
		ret = strndup(save, len);
	parse_save(len, ft_strlen(save) - len);
	printf("buffer after = |%s|\n", save);
	*line = ret;
	if (!ret)
		return (0);
	return (1);
}

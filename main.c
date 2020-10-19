#include "get_next_line.h"

int main(void)
{
	int fd = open("/dev/null", O_RDONLY);
	int size = 1;
	int i = 0;
	char **dst = malloc(sizeof(char*) * size);

	while (i < size)
	{
		printf("ret = %d", get_next_line(fd, &dst[i]));
		printf("|%s|\n", dst[i]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		free(dst[i]);
		i++;
	}
	close(fd);
	return (0);
}

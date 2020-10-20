#include "get_next_line.h"

int main(void)
{
	int fd = open("/dev/null", O_RDONLY);
	int size = 100;
	int i = 0;
	int ret = 1;
	char **dst = malloc(sizeof(char*) * size);

	while (i < size && ret > 0)
	{
		ret = get_next_line(fd, &dst[i]);
		printf("ret = %d", ret);
		printf("|%s|\n", dst[i]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		free(dst[i]);
		i++;
	}

	// unsigned char c;
	// printf("%zd\n", read(fd, &c, 1));
	// printf("|%d|\n", c);
	// printf("|%c|\n", c);

	close(fd);
	return (0);
}

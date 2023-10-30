
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void l(void)
{
	system("leaks a.out");
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *temp;
	while (temp = get_next_line(fd))
	{
		printf("str: %s\n", temp);
		free(temp);
	}
	return (0);
}
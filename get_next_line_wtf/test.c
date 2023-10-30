
#include "gnl.h"
#include <stdio.h>

int main(void)
{
	char *temp;
	while (temp = get_next_line(0))
	{
		printf("str: %s\n", temp);
	}
	return (0);
}
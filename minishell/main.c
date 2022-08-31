#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>



int main(void)
{
	char *str;

	while (1)
	{
		str = readline("prompt : ");
		if (str)
			printf("%s\n", str);
		else
			break;
		add_history(str);
		free(str);
	}
	return (0);
}
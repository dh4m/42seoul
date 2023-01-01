#include <iostream>
#include <cctype>

char	*upper_str(char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (islower(str[i]))
			str[i] = toupper(str[i]);
		i++;
	}
	return (str);
}

int main(int argc, char *argv[])
{
	int	i = 1;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	while (argv[i])
	{
		std::cout << upper_str(argv[i]);
		i++;
	}
	std::cout << '\n';
	return (0);
}
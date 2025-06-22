#include <unistd.h>

void	mod_char(char s)
{
	char opt;
	if (s >= 'A' && s <= 'Z')
	{
		opt = 'Z' - s + 'A';
	}
	write (1, &opt, 1);
}


int	main(int ac, char **av)
{
	int i;
	i = 0;
	if (ac != 2)
		return (write(1, "\n", 1), 1);
	while (av[1][i] != '\0')
	{
		mod_char(av[1][i]);
		i++;
	}
}
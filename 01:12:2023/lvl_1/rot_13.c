#include <unistd.h>

void	rot_13(char s)
{
	char opt;
	if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z'))
	{
		if ((s >= 'A' && s <= 'M') || (s >= 'a' && s <= 'm'))
			opt = s + 13;
		else if ((s >= 'N' && s <= 'Z') || (s >= 'n' && s <= 'z'))
			opt = s - 13;
		write (1, &opt, 1);
	}
	else
		write(1, &s, 1);

}

int	main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac != 2)
		return(write(1, "\n", 1), 1);
	while(av[1][i] != '\0')
	{
		rot_13(av[1][i]);
		i++;
	}
	write(1, "\n", 1);
}
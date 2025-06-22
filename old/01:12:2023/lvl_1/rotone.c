#include <unistd.h>

void	cal_char(char s)
{
	char opt;

	if (s >= 'A' && s <= 'Z')
	{
		if (s >= 'A' && s <= 'Y')
		{
			opt = (s - '0') +1 + '0';
		}
		else if (s == 'Z')
			opt = 'A';
	}
	else if (s >= 'a' && s <= 'z')
	{
		if (s >= 'a' && s <= 'y')
		{
			opt = (s - '0') +1 + '0';
		}
		else if (s == 'z')
			opt = 'a';
	}
	else
		opt = s;
	write(1, &opt, 1);
}


int	main(int ac, char **av)
{
	int i;
	i= 0;
	if (ac != 2)
		return (write(1, "\n", 1), 1);
	while (av[1][i] != '\0')
	{
		cal_char(av[1][i]);
		i++;
	}
	write (1, "\n", 1);
}
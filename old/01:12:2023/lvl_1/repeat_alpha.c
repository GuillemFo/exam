#include <unistd.h>

void	ft_repeat(char s)
{
	int  i;
	i = 1;
	if (s >= 'A' && s <= 'Z')
	{
		i = s - 'A' +1;
		while (i > 0)
		{
			write(1, &s, 1);
			i--;
		}
	}
	else if (s >= 'a' && s <= 'z')
	{
		i = s - 'a' +1;
		while (i > 0)
		{
			write(1, &s, 1);
			i--;
		}
	}
	else
		write(1, &s, 1);
}


int	main(int ac, char **av)
{
	int i;
	i = 0;
	if (ac != 2)
		return (write(1, "\n", 1), 1);
	while (av[1][i] != '\0')
	{
		ft_repeat(av[1][i]);
		i++;
	}
	write(1, "\n", 1);
}
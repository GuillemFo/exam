#include <unistd.h>

void	ft_rev(char *s)
{
	int	i;
	int len;
	len = 0;
	i = 0;
	while (s[len] != '\0')
		len++;
	while (len > 0)
	{
		write(1, &s[len -1], 1);
		len--;
	}
}



int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1));
	ft_rev(av[1]);
	write(1, "\n", 1);
}
